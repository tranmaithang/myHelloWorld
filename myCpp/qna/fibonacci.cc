//Generate Fibonacci number and sequence by iterative and recursive method
//Written by Thu Phuong DO
//Last modified: 2015-11-22
//Note: Coursera - Initation C++ by Ecole Polytechnique de Lausanne

#include <iostream>
#include <vector>

using namespace std;

//----------------------Prototype-------------------------------------//
int Fibonacci (int n);
int FibonacciIterative(int n);
vector<int> FibonacciSequence(int n);
void display_vector(const vector<int> V);
//--------------------------------------------------------------------//

int main()
{
	int n;
	cout << "Enter an integer number from 0 to 40 : ";
	cin >> n;
	
	cout << "Iterative method: F(" << n << ") = " << FibonacciIterative(n) << endl;
	cout << "Recursive method: F(" << n << ") = " << Fibonacci(n) << endl;
	
	cout << "Fibonacci sequence: ";
	display_vector(FibonacciSequence(n));
	cout << endl;
	return 0;
}

//-----------Recursive method-----------------//
int Fibonacci (int n)
{
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
		}
	else {
		return Fibonacci(n-1) + Fibonacci(n-2);
		}
}
//---------------------------------------------//

//------------Iterative method-----------------// 

int FibonacciIterative(int n)
{
  int Fn(0);    // stock F(i)  , initialised asF(0)
  int Fn_1(Fn); // stock F(i-1), initialised as F(0)
  int Fn_2(1);  // stock F(i-2), initialised as F(1)

  if (n > 0) {
    for (int i(1); i <= n; ++i) {
      Fn   = Fn_1 + Fn_2;    // if n>=1, calculate F(n)=F(n-1)+F(n-2)
      Fn_2 = Fn_1;           // 
      Fn_1 = Fn;
    }
 }
  return Fn;
}

//------------Fibonacci sequence-----------------//
vector<int> FibonacciSequence(int n)
{
	vector<int> F(n+1);
	F[0] = 0;
	F[1] = 1;
	
	if (n > 0) {
		for (int i(2); i <= n; ++i) {
		F[i]   = F[i-1] + F[i-2];    
		}
	}    
    return F;	
}
//---------------------------------------------//

//Display the content of vector
void display_vector(const vector<int> V)
{
	for (size_t i(0); i < V.size(); ++i) {
		cout << V[i] << " ";
	}
		cout << endl;
}
