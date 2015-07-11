// C++
// Tutorials C++ from cplusplus.com

// Pointers to base class
// One of the key features of class inheritance is that a pointer to a derived class is
// type-compatible with a pointer to its base class. Polymorphism is the art of taking 
// advantage of this simple but powerful and versatile feature.

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
	Polygon* ppoly1 = &rect;
	Polygon* ppoly2 = &trgl;
	ppoly1->set_values(4, 5);	// Because the type of ppoly1 and ppoly2 is pointer to Polygon, we have to use operator '->' instead of '.'
	ppoly2->set_values(4, 5);
	cout << rect.area() << '\n';
	cout << trgl.area() << '\n';
	system("pause");
	return 0;
}
