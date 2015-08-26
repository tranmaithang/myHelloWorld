Attribute VB_Name = "PM_PF"
'----------------'
'Sharpe ratio
'----------------'

Function pm_pf_Sharpe(ValueMatrix, Rf As Double, freq As String) As Double
Dim R_p As Double, sigma_p As Double

R_p = pm_st_MeanReturn(ValueMatrix, "d")
sigma_p = pm_st_Volatility(ValueMatrix, "d")

pm_pf_Sharpe = (R_p - Rf) / sigma_p
End Function

'----------------'
'Treynor ratio
'----------------'

Function pm_pf_Treynor(ValueMatrix, Bmk, Rf As Double, freq As String) As Double
Dim R_p As Double, beta_p As Double
Dim R_bmk As Double

R_p = pm_st_MeanReturn(ValueMatrix, "d")
R_bmk = pm_st_MeanReturn(Bmk, "d")
beta_p = pm_st_Beta(ValueMatrix, Bmk)

pm_pf_Treynor = (R_p - Rf) / beta_p
End Function

'-----------------------------------------------------------------'
'Calculate the excess return of a portfolio over that of benchmark'
'-----------------------------------------------------------------'

Function pm_pf_ExcessReturn(ValueMatrix, Bmk)
Dim R_p, R_bmk

R_p = pm_st_ArithReturn(ValueMatrix)
R_bmk = pm_st_ArithReturn(Bmk)

pm_pf_ExcessReturn = pm_ff_MAddSubtract(R_p, R_bmk, "Subtract")
End Function

'-----------------------------------------------------------'
'Calculate the tracking difference: average of excess return'
'-----------------------------------------------------------'

Function pm_pf_TrackingDiff(ValueMatrix, Bmk, freq As String)
Dim R_diff

R_diff = pm_pf_ExcessReturn(ValueMatrix, Bmk)

Select Case freq
Case "d"
    pm_pf_TrackingDiff = Application.Average(R_diff) * 250
Case "w"
    pm_pf_TrackingDiff = Application.Average(R_diff) * 52
Case "m"
    pm_pf_TrackingDiff = Application.Average(R_diff) * 12
End Select

End Function

'-------------------------------------------------------------'
'Calculate the tracking error: the volatility of excess return'
'-------------------------------------------------------------'

Function pm_pf_TrackingError(ValueMatrix, Bmk, freq As String)
Dim R_diff
R_diff = pm_pf_ExcessReturn(ValueMatrix, Bmk)

Select Case freq
Case "d"
    pm_pf_TrackingError = Application.StDev(R_diff) * Sqr(250)
Case "w"
    pm_pf_TrackingError = Application.StDev(R_diff) * Sqr(52)
Case "m"
    pm_pf_TrackingError = Application.StDev(R_diff) * Sqr(12)
End Select

End Function

'-------------------------------'
'Calculate the information ratio'
'-------------------------------'

Function pm_pf_IR(ValueMatrix, Bmk, freq As String) As Double
Dim TD As Double, TE As Double

'Tracking difference
TD = pm_pf_TrackingDiff(ValueMatrix, Bmk, freq)
'Tracking error
TE = pm_pf_TrackingError(ValueMatrix, Bmk, freq)

pm_pf_IR = TD / TE
End Function

'----------------------'
'Caculate Sortino ratio'
'----------------------'

Function pm_pf_Sortino(ValueMatrix, MAR As Double, freq As String) As Double
Dim SemiDev As Double
Dim R As Double

SemiDev = pm_st_SemiDeviation(ValueMatrix, MAR, freq)
R = pm_st_MeanReturn(ValueMatrix, freq)

pm_pf_Sortino = (R - MAR) / SemiDev
End Function

'--------------------------'
'Calculate Maximum Drawdown'
'--------------------------'
Function pm_pf_MaxDrawdown(ValueMatrix)

End Function
