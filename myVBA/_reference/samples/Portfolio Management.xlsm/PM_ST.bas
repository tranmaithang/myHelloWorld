Attribute VB_Name = "PM_ST"
'''PORTFOLIO MANAGEMENT
'Stock Analysis

Option Explicit
Option Base 1
Public Const nResult As Byte = 8

'--------------------------------------------------'
'Calculate arithmetic return from an array of price'
'--------------------------------------------------'

Function pm_st_ArithReturn(PriceMatrix)
Attribute pm_st_ArithReturn.VB_ProcData.VB_Invoke_Func = " \n21"
Dim R() As Double
Dim n As Long, nStock As Long
Dim i As Long, j As Long

n = pm_ff_Dimension(PriceMatrix)
nStock = pm_ff_Dimension(PriceMatrix, 1)

ReDim R(1 To n - 1, 1 To nStock)

For i = 1 To n - 1
    For j = 1 To nStock
        R(i, j) = PriceMatrix(i + 1, j) / PriceMatrix(i, j) - 1
    Next j
Next i
    pm_st_ArithReturn = R
End Function

'---------------------------------------------------------'
'Calculate historical average return for a series of price'
'---------------------------------------------------------'

Function pm_st_MeanReturn(Price, freq As String) As Double
'Annualized return of stock
'freq: Frequency
'd=day
'w=week
'm=month

Dim ret As Double
Dim R

R = pm_st_ArithReturn(Price)
ret = Application.Average(R)

Select Case freq
Case "d"
    pm_st_MeanReturn = ret * 250
Case "w"
    pm_st_MeanReturn = ret * 52
Case "m"
    pm_st_MeanReturn = ret * 12
End Select
End Function

'------------------------------------------------------'
'Calculate volatility from a series of price'
'------------------------------------------------------'
Function pm_st_Volatility(Price, freq As String)
Dim Vol As Double
Dim R

R = pm_st_ArithReturn(Price)
Vol = Application.StDev(R)

Select Case freq
Case "d"
    pm_st_Volatility = Vol * Sqr(250)
Case "w"
    pm_st_Volatility = Vol * Sqr(52)
Case "m"
    pm_st_Volatility = Vol * Sqr(12)
End Select

End Function

Function pm_st_Stats(PriceMatrix, freq As String)
Dim Result() As Variant
Dim Nobs As Long, nStock As Long, Rnobs As Long
Dim Ravg As Double, Rvol As Double, Rskew As Double
Dim Rkurt As Double, Rmax As Double, Rmin As Double, Rmedian As Double
Dim R

R = pm_st_ArithReturn(PriceMatrix)
ReDim Result(1 To nResult, 1 To 2)

Nobs = pm_ff_Dimension(PriceMatrix)

Rnobs = Nobs
Ravg = pm_st_MeanReturn(PriceMatrix, freq)
Rvol = pm_st_Volatility(PriceMatrix, freq)
Rskew = Application.Skew(R)
Rkurt = Application.Kurt(R)
Rmax = Application.Max(R)
Rmin = Application.Min(R)
Rmedian = Application.Median(R)

'Row title
Result(1, 1) = "Nobs"
Result(2, 1) = "Mean"
Result(3, 1) = "Volatility"
Result(4, 1) = "Skewness"
Result(5, 1) = "Kurtosis"
Result(6, 1) = "Max"
Result(7, 1) = "Min"
Result(8, 1) = "Median"

'Print results
Result(1, 2) = Rnobs
Result(2, 2) = Format(Ravg, "Percent")
Result(3, 2) = Format(Rvol, "Percent")
Result(4, 2) = Format(Rskew, "Standard")
Result(5, 2) = Format(Rkurt, "Standard")
Result(6, 2) = Format(Rmax, "Percent")
Result(7, 2) = Format(Rmin, "Percent")
Result(8, 2) = Format(Rmedian, "Percent")

pm_st_Stats = Result
End Function

'------------------'
'Correlation matrix'
'------------------'

Function pm_st_CorrelMatrix(PriceMatrix)
Dim C() As Double
Dim R
Dim nStock As Long
Dim cor As Double
Dim i As Long, j As Long

R = pm_st_ArithReturn(PriceMatrix)
nStock = pm_ff_Dimension(PriceMatrix, 1)


ReDim C(1 To nStock, 1 To nStock) As Double
For i = 1 To nStock
    For j = 1 To nStock
        cor = Application.Correl(Application.Index(R, , i), Application.Index(R, , j))
        If i <> j Then
            C(i, j) = Format(cor, "0.0000")
        Else
            C(i, j) = cor
        End If
    Next j
Next i
pm_st_CorrelMatrix = C
End Function

'---------------------------------------------------'
'Convert a correlation matrix into covariance matrix'
'---------------------------------------------------'

Function pm_st_Cor2Cov(CorrelMatrix, VolMatrix)
'VolMatrix: 1*n

Dim Cov() As Double
Dim i As Integer, j As Integer, n As Integer
Dim C As Double
Dim CorMat, Vol

n = pm_ff_Dimension(CorrelMatrix)

ReDim Cov(1 To n, 1 To n)
CorMat = CorrelMatrix
Vol = VolMatrix

For i = 1 To n
    For j = 1 To n
        C = CorMat(i, j) * Vol(1, i) * Vol(1, j)
        Cov(i, j) = Format(C, "0.000000")
    Next j
Next i
    pm_st_Cor2Cov = Cov
End Function

'-------------------------------------------------------'
'Estimate the raw beta from a series of historical price
'-------------------------------------------------------'

Function pm_st_Beta(PriceMatrix, Bmk)
'PriceMatrix: Array of price
'Bmk: Array of benchmark
Dim Rstock, Rmkt

Rstock = pm_st_ArithReturn(PriceMatrix)
Rmkt = pm_st_ArithReturn(Bmk)

pm_st_Beta = Application.WorksheetFunction.Slope(Rstock, Rmkt)
End Function

'------------------------------------------------------------'
'Estimate the adjusted beta from a series of historical price
'------------------------------------------------------------'
Function pm_st_Beta_Adjusted(PriceMatrix, Bmk)
'Assumption: the beta of a stock will move towards that of the market overtime
Dim rawB As Double

rawB = pm_st_Beta(PriceMatrix, Bmk)
pm_st_Beta_Adjusted = rawB * 2 / 3 + 1 * 1 / 3
End Function

'----------------------------'
'Calculate the Semi Deviation'
'----------------------------'

Function pm_st_SemiDeviation(PriceMatrix, MAR As Double, freq As String)
'MAR: Minimum Acceptable Return
Dim R
R = pm_st_ArithReturn(PriceMatrix)

Dim avg As Double, temp1 As Double, temp2 As Double
Dim i As Long, j As Long, n As Long
Dim SemiDeviation As Double

i = 0
temp1 = 0
temp2 = 0
n = pm_ff_Dimension(PriceMatrix) - 1

For j = 1 To n
   If R(j, 1) < MAR Then
      temp1 = temp1 + R(j, 1)
      i = i + 1
   End If
Next j
avg = temp1 / i

For j = 1 To n
   If R(j, 1) < MAR Then
      temp2 = temp2 + (R(j, 1) - avg) ^ 2
   End If
Next j

SemiDeviation = Sqr(temp2 / i)

Select Case freq
Case "d"
    pm_st_SemiDeviation = SemiDeviation * Sqr(250)
Case "w"
    pm_st_SemiDeviation = SemiDeviation * Sqr(52)
Case "m"
    pm_st_SemiDeviation = SemiDeviation * Sqr(12)
End Select
End Function

'------------------------------'
'Quantile of a series of return'
'------------------------------'

Function pm_st_FreqPct(Price, nbInterval As Integer)

Dim n As Long, i As Long
Dim R_max As Double, R_min As Double, s As Double
Dim Intvl() As Double       'Interval range
Dim freqPct() As Double
Dim v As Double
Dim FQ, R

n = pm_ff_Dimension(Price) - 1

ReDim Intvl(1 To nbInterval, 1 To 1) As Double
ReDim freqPct(1 To nbInterval, 1 To 2) As Double

R = pm_st_ArithReturn(Price)
R_max = Application.Max(R)
R_min = Application.Min(R)
s = (R_max - R_min) / (nbInterval - 1)


v = R_min
For i = 1 To nbInterval
    Intvl(i, 1) = v + s * (i - 1)
Next i

FQ = Application.frequency(R, Intvl)

'Frequency of returns in percentage
For i = 1 To nbInterval
    freqPct(i, 1) = Format(Intvl(i, 1), "0.0000")
    freqPct(i, 2) = FQ(i, 1) / n
Next i

pm_st_FreqPct = freqPct
End Function

'-------------------------------'
'Histogram of a series of return'
'-------------------------------'

Sub pm_st_Histogram()
Dim Price As Range
Dim nbInterval As Integer

On Error GoTo ErrHandler

Set Price = Application.InputBox(prompt:="Select stock price range", Title:="Stock price", Type:=8)
nbInterval = InputBox(prompt:="Enter number of intervals", Title:="Interval")
    
Dim freqPct
freqPct = pm_st_FreqPct(Price, nbInterval)

ActiveSheet.Shapes.AddChart.Select
ActiveChart.ChartType = xlColumnClustered

With ActiveChart.SeriesCollection.NewSeries
    .XValues = Application.Index(freqPct, , 1)
    .Values = Application.Index(freqPct, , 2)
End With

'Bar chart
With ActiveChart.SeriesCollection.NewSeries
    .Values = Application.Index(freqPct, , 2)
    .ChartType = xlXYScatterSmooth
End With

'Add bell curve
With ActiveChart
    .HasLegend = False
    .Axes(xlValue).HasMajorGridlines = False
    .Axes(xlValue).HasMinorGridlines = False
End With

ErrHandler:
Exit Sub
End Sub



