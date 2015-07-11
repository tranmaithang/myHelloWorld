// C++
// Tutorials C++ from cplusplus.com

// Loops
// i. Iteration statements (while, do while, for) repeat a statement a certain number 
//	  of times, or while a condition is fulfilled. 
// ii. Jump statements (break, continue, goto) allow altering the flow of a program
//     by performing jumps to specific locations.

#include <iostream>
#include <string>
using namespace std;

// The white loop
void white_loop()
{
	int n = 10;
	cout << "White loop\n";
	while (n > 0) 
	{
		cout << n << ", ";
		--n;
	}
	cout << "liftoff!\n" << endl;
}

// The for loop
void for_loop()
{
	cout << "For loop\n";
	for (int n = 10; n > 0; n--) 
	{
		cout << n << ", ";
	}
	cout << "liftoff!\n" << endl;
}

// The break statement
void break_statement()
{
	cout << "Break statement\n";
	for (int n = 10; n > 0; n--)
	{
		cout << n << ", ";
		if (n == 3)
		{
			cout << "countdown aborted! if (n == 3)\n" << endl;
			break;
		}
	}
}

// The continue statement
void continue_statement()
{
	cout << "Continue statement\n";
	for (int n = 10; n > 0; n--) 
	{
		if (n == 5)
		{
			cout << "continue! if (n == 5), ";
			continue;
		}
		cout << n << ", ";
	}
	cout << "liftoff!\n" << endl;
}

// The goto statement
void goto_statement()
{
	int n = 10;
	cout << "Goto statement\n";
mylabel:
	cout << n << ", ";
	n--;
	if (n > 0)
		goto mylabel;
	cout << "countdown aborted! if (n > 0), ";
	cout << "liftoff!\n" << endl;
}

int main()
{
	string str;
	do 
	{
		cout << "=== ITERATION STATEMENTS (LOOPS) ===\n" << endl;
		white_loop();
		for_loop();
		break_statement();
		continue_statement();
		goto_statement();
		cout << "Do it again (y/n)?";
		getline(cin, str);
		cout << endl;
	} 
	while (str != "n");
	return 0;
}