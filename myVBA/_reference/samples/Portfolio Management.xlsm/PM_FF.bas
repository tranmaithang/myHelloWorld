Attribute VB_Name = "PM_FF"
'''PORTFOLIO MANAGEMENT
'Fundamental functions
'Written by Phuong DO

Option Explicit
Option Base 1

'--------------------------------'
'Dimension of a range or an array'
'--------------------------------'

Function pm_ff_Dimension(Matrix, Optional i As Byte = 0)
'i = 0: number of rows (by default)
'i = 1: number of columns
Dim n As Long

If i = 0 Then
    If TypeName(Matrix) = "Range" Then
        n = Matrix.Rows.Count
    Else
        n = UBound(Matrix)
    End If
ElseIf i = 1 Then
    If TypeName(Matrix) = "Range" Then
        n = Matrix.Columns.Count
    Else
        n = UBound(Matrix, 2)
    End If
End If
pm_ff_Dimension = n
End Function

'------------------------'
'Add or Subtract 2 matrix'
'------------------------'

Function pm_ff_MAddSubtract(matrix1, matrix2, Optional TypeOperation As String = "Add")
Dim diff() As Double
Dim m As Long, n As Long
Dim i As Long, j As Long

n = pm_ff_Dimension(matrix1)
m = pm_ff_Dimension(matrix1, 1)

ReDim diff(1 To n, 1 To m)
For j = 1 To n
    For i = 1 To m
        If TypeOperation = "Add" Then
            diff(j, i) = matrix1(j, i) + matrix2(j, i)
        ElseIf TypeOperation = "Subtract" Then
            diff(j, i) = matrix1(j, i) - matrix2(j, i)
        End If
    Next i
Next j

pm_ff_MAddSubtract = diff
End Function
