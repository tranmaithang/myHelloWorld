#include <iostream>
using namespace std;

int Fibonacci (int n);
int FibonacciIteratif(int n);

int main()
{
	int n;
	cout << "Entrez un nombre entier compris entre 0 et 40 : ";
	cin >> n;
	
	cout << "Methode iterative: F(" << n << ") = " << FibonacciIteratif(n) << endl;
	cout << "Methode recursive: F(" << n << ") = " << Fibonacci(n) << endl;
	return 0;
}

//methode recursive
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

//methode iterative
int FibonacciIteratif(int n)
{
  int Fn(0);    // stocke F(i)  , initialisé par F(0)
  int Fn_1(Fn); // stocke F(i-1), initialisé par F(0)
  int Fn_2(1);  // stocke F(i-2), initialisé par F(-1)

  if (n > 0)
    for (int i(1); i <= n; ++i) {
      Fn   = Fn_1 + Fn_2;    // pour n>=1 on calcule F(n)=F(n-1)+F(n-2)
      Fn_2 = Fn_1;           // et on decale...
      Fn_1 = Fn;
    }
  return Fn;
}
