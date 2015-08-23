// ALGORITHM 
// Max - Calculate max of an array 
// Interview : Societe Generale - Trader Assitant - 12-Mar-2014
// Interview : PNP Paribas - Trader Assitant - 27-Mar-2014

// Author : TMT
// Created on November 16, 2014, 12:08 PM 

#include <iostream>
#include <array>
using namespace std;

int maxArray1(int arg[], int size)
{
	int max = arg[0];
	for (int i = 1; i < size; i++)
	{
		if (arg[i]>max) max = arg[i];
		else max = max;
	}
	return max;
}

int maxArray2(array <int, 5> arg)
{
	int max = arg[0];
	for (int i = 1; i < 5; i++)
	{
		if (arg[i]>max) max = arg[i];
		else max = max;
	}
	return max;
}

int main()
{
	int myArray1[5] = { 2, 5, 3, 4, 10 };
	array < int, 5> myArray2 = { 2, 5, 3, 1, 9 };

	cout << "=== CACULATING MAX OF AN ARRAY ===" << endl;
	cout << endl;
	cout << "Max of array { 2, 5, 3, 4, 10 } : " << maxArray1(myArray1, 5) << endl;
	cout << "Max of array { 2, 5, 3, 1, 9 } : " << maxArray2(myArray2) << endl;
	cout << endl;
	system("pause");
	return 0;
}
