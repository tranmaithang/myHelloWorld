// ALGORITHM 
// Check asymmetry of a word 
// Interview : Societe Generale - PnL Analyst - 06-Nov-2014

// Author : TMT
// Created on November 16, 2014, 12:27 PM 

#include <iostream>
#include <string>
#include <array>
using namespace std;

bool isAsymmetry(string aString)
{
	bool test = true;
	for (size_t i = 0; i < aString.size(); i++)
	{
		if (aString[i] != aString[aString.size() - i - 1])
		{
			test = false;
			break;
		}
	}
	return test;
}

int main()
{
	string str;
	string myString;

	cout << "=== CHECK ASYMMETRY OF A WORD ===" << endl;
	do
	{
		cout << endl;
		cout << "Give a word : ";
		cin >> myString;
		cout << myString << " is asymmetric ? : " << isAsymmetry(myString) << endl;
		cout << endl;
		cout << "Do it again (y/n) ?";
		cin >> str;
	} 
	while (str != "n");
	return 0;
}
