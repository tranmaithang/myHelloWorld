// C++
// Tutorials C++ from cplusplus.com

// Virtual members
// A virtual member is a member function that can be redefined in a derived class,  
// while preserving its calling properties through references.

#include <iostream>
using namespace std;

class Polygon
{
protected:
	int width, height;
public:
	void set_values(int a, int b)
	{
		width = a;
		height = b;
	}
	virtual int area()	// vitual function
	{
		return 0;
	}
};

class Rectangle : public Polygon
{
public:
	int area()	
	{
		return width * height;
	}
};

class Triangle : public Polygon
{
public:
	int area()	
	{
		return width * height / 2;
	}
};

int main() 
{
	Rectangle rect;
	Triangle trgl;
	Polygon poly;
	Polygon* ppoly1 = &rect;
	Polygon* ppoly2 = &trgl;
	Polygon* ppoly3 = &poly;
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	ppoly3->set_values(4, 5);
	cout << ppoly1->area() << '\n';	// child class function overloading
	cout << ppoly2->area() << '\n';	// child class function overloading
	cout << ppoly3->area() << '\n';	
	system("pause");
	return 0;
}
