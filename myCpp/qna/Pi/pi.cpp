// ALGORITHM
// Calculate pi
// Interview : Societe Generale - Trader Assitant - 20-Nov-2014

// Author : TMT
// Created on November 20, 2014, 18:57 

#include <iostream>
#include <string>
#include <cmath>
#include <random>
using namespace std;

// Random double between 0-1
double random01()
{
	return ((double)rand() / (double)(RAND_MAX)) * 2 - 1;
}

// Algo 1
double pi_1(int n)
{
	double radius = 1;
	double dx = radius / n;

	double surf_circle = 0;
	for (int i = 0; i < n; i++)
	{
		surf_circle += dx * sqrt(1 - pow(i * dx, 2));
	}

	return (4 * surf_circle / pow(radius, 2));
}

// Algo 2
double pi_2(int n)
{
	double radius = 1;
	double counter = 0;

	for (int i = 0; i < n; i++)
	{
		double x = random01();
		double y = random01();
		if (pow(x, 2) + pow(y, 2) < 1)
		{
			counter += 1;
		}
	}

	double prob = counter / n;
	double surf_square = pow(2 * radius, 2);
	double surf_circle = prob * surf_square;
	return (surf_circle / pow(radius, 2));
}

int main()
{
	int n;
	string str;

	cout << "=== CALCULATE PI ===" << endl;
	do
	{
		cout << endl;
		cout << "Give a number of simulation: ";
		cin >> n;
		cout << "Algo 1. Pi : " << pi_1(n) << endl;
		cout << "Algo 2. Pi : " << pi_2(n) << endl; 
		cout << endl;
		cout << "Do it again (y/n) ?";
		cin >> str;
	} 
	while (str != "n");
	return 0;

}