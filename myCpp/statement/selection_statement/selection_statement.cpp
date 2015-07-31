// C++
// Tutorials C++ from tutorialspoint.com

// Selection statements

#include <iostream>
using namespace std;

void ifelse_statement(char grade)
{
	cout << "If...else statement " << endl;
	if (grade == 'A')
		cout << "Excellent!" << endl;
	else if (grade == 'B' || grade == 'C')
		cout << "Well done" << endl;
	else if (grade == 'D')
		cout << "You passed" << endl;
	else if (grade == 'E' || grade == 'F')
		cout << "Better try again" << endl;
	else
		cout << "Invalid grade" << endl;

	cout << "Your grade is " << grade << endl << endl;
}

void switch_statement(char grade)
{
	cout << "Switch statement " << endl;
	switch (grade)
	{
	case 'A':
		cout << "Excellent!" << endl;
		break;
	case 'B':
	case 'C':
		cout << "Well done" << endl;
		break;
	case 'D':
		cout << "You passed" << endl;
		break;
	case 'E':
	case 'F':
		cout << "Better try again" << endl;
		break;
	default:
		cout << "Invalid grade" << endl;
	}
	cout << "Your grade is " << grade << endl << endl;
}

int main()
{
	char c;
	cout << "=== SELECTION STATEMENTS ===\n" << endl;
	cout << "What is your grade (A,B,C,D,E)?";
	cin >> c;
	ifelse_statement(c);
	switch_statement(c);
	system("pause");
	return 0;
}