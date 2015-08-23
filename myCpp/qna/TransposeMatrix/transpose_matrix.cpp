// ALGORITHM 
// Tranpose of a matrix 
// Interview : Societe Generale - PnL Analyst - 06-Nov-2014

// Author : TMT
// Created on November 16, 2014, 12:22 PM 

#include <iostream>
#include <array>
using namespace std;

void tranposeMatrix(int arg[3][3])
{
	int saveValue;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			saveValue = arg[i][j];
			arg[i][j] = arg[j][i];
			arg[j][i] = saveValue;
		}
	}
}

int main()
{
	int myMatrix1[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	cout << "=== TRANSPOSE OF AN MATRIX ===" << endl;
	cout << endl;

	cout << "Tranpose of matrix : " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << myMatrix1[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	cout << "New matrix : " << endl;
	tranposeMatrix(myMatrix1);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << myMatrix1[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}
