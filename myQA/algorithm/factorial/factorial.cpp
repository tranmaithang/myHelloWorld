// ALGORITHM 
// Factorial - Tinh giai thua
// Interview : PNP Paribas - Trader Assitant - 27-Mar-2014

// Author : TMT
// Created on November 16, 2014, 12:08 PM 

#include <iostream>
#include <string>
using namespace std;

int factorial1(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

int factorial2(int n)
{
	if (n > 1)
		return (n*factorial2(n - 1)); // Recursivity
	else
		return 1;
}

int main()
{
	int n;
	string str;

	cout << "=== CACULATING FACTORIAL ===" << endl;
	do
	{
		cout << endl;
		cout << "Give a number : ";
		cin >> n;
		cout << "Factorial of " << n << " is : " << factorial1(n) << endl;
		cout << "Factorial of " << n << " is : " << factorial2(n) << endl;
		cout << endl;
		cout << "Do it again (y/n) ?";
		cin >> str;
	} 
	while (str != "n");
	return 0;
}
