// ALGORITHM 
// Sort of an array
// Interview : PNP Paribas - Trader Assitant - 27-Mar-2014

// Author : TMT
// Created on November 16, 2014, 12:19 PM 

#include <iostream>
#include <array>
#include <cmath>
using namespace std;

int* sortArray1(int arg[], int size)	// Pass array to function and return array from functions by pointer
{
	int saveValue;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arg[i] < arg[j])
			{
				saveValue = arg[i];
				arg[i] = arg[j];
				arg[j] = saveValue;
			}
		}
	}
	return arg;
}

void sortArray2(int arg[], int size)
{
	int saveValue;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arg[i] < arg[j])
			{
				saveValue = arg[i];
				arg[i] = arg[j];
				arg[j] = saveValue;
			}
		}
	}
}

array <int, 5> sortArray3(array <int, 5> arg)	// Pass array to function and return array from functions
{   
	int saveValue;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arg[i] < arg[j])
			{
				saveValue = arg[i];
				arg[i] = arg[j];
				arg[j] = saveValue;
			}
		}
	}
	return arg;
}


int main()
{
	int myArray1[5] = { 2, 5, 3, 4, 10 };
	array < int, 5> myArray2 = { 2, 5, 3, 1, 9 };

	cout << "=== SORT OF AN ARRAY ===" << endl;
	cout << endl;

	cout << "Sort data of array { 2, 5, 3, 4, 10 } : ";
	int* mysortArray1 = sortArray1(myArray1, 5);
	for (int i = 0; i < 5; i++)
	{ 
		cout << *(mysortArray1 + i) << " "; 
	}
	cout << endl;

	cout << "Sort data of array { 2, 5, 3, 4, 10 } : ";
	sortArray2(myArray1, 5);
	for (int i = 0; i < 5; i++)
	{ 
		cout << myArray1[i] << " "; 
	}
	cout << endl;

	cout << "Sort data of array { 2, 5, 3, 1, 9 } : ";
	array < int, 5> mysortArray2 = sortArray3(myArray2);
	for (size_t i = 0; i < mysortArray2.size(); i++)
	{ 
		cout << mysortArray2[i] << " "; 
	}
	cout << endl;

	cout << endl;
	system("pause");
	return 0;
}
