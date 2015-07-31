// C++
// Tutorials C++ from cplusplus.com

// Abstract base class
// Abstract base classes are something very similar to the Polygon class in the previous
// example. They are classes that can only be used as base classes, and thus are allowed
// to have virtual member functions without definition (known as pure virtual functions).

#include <iostream>
using namespace std;

class Polygon 
{
protected:
	int width, height;
public:
	Polygon(int a, int b) : width(a), height(b) {}
	void set_values(int a, int b)
	{
		width = a;
		height = b;
	}
	virtual int area(void) = 0;
};

class Rectangle : public Polygon 
{
public:
	Rectangle(int a, int b) : Polygon(a, b) {};
	int area(void)
	{
		return (width * height);
	}
};

class Triangle : public Polygon 
{
public:
	Triangle(int a, int b) : Polygon(a, b) {};
	int area(void)
	{
		return (width * height / 2);
	}
};

int main() 
{
	Polygon* ppoly1 = new Rectangle(4, 5);
	Polygon* ppoly2 = new Triangle(4, 5);
	cout << ppoly1->area() << '\n';
	cout << ppoly2->area() << '\n'; 
	system("pause");
	return 0;
}
