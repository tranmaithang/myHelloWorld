//Purpose: Find the number where sum of all digits is equal to product of digits. Example: 44
//Written by: Thu Phuong DO
//Last modified: 2015-11-22
//Note: Coursera - Initation C++ by Ecole Polytechnique de Lausanne

#include <iostream>
using namespace std;

//--------------------------------------------------------------------//
//						PROTOTYPES									  //	
int sum (int n);
int product (int n);
bool sum_product_equal(int n);
//--------------------------------------------------------------------//

int main()
{
	int nb(0); 
	int x(10);
	//Display 20 number that satisfied the condition
	cout << "20 numbers that have the sum of digits is equal to the product of digits: " << endl;
	
	while (nb < 20) {
		if (sum_product_equal(x) == true) {
			cout << x << ", ";
			nb+=1;
		}		
		x+=1;
	}
	cout << endl;
	return 0;
}

//--------------------------------------------------//
//Calculate the sum of all digits of an integer number
int sum (int n)
{
	int x(n);
	int result(0); 
	while (x>0)
	{
		int residual_division; //the residual or modulo of division of x by 10
		residual_division = x % 10;
		result += residual_division; 
		x /= 10;
	}
	return result;
}

//------------------------------------------------------//
//Calculate the product of all digits of an integer number
int product (int n)
{
	int x(n);
	int result(1); 
	while (x>0)
	{
		int residual_division; 
		residual_division = x % 10;
		result *= residual_division; 
		x /= 10;
	}
	return result;
}

//------------------------------------------------------//
//Test if an integer number satisfies the condition
bool sum_product_equal(int n)
{
	if (sum(n) == product(n)) {
		return true;
	}
	else {
		return false;
	}
}
