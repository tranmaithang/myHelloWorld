// ALGORITHM 
// Maths puzzle - Place the digits from 1 to 9 in the blank 

// Author : TMT
// Created on May 23, 2015, 16:04 PM 

#include <iostream>
using namespace std;

int main()
{
	cout << "=== MATHS PUZZLE ===" << endl;
	cout << "Place the digits from 1 to 9 in the blank :" << endl;
	cout << "_ + 13.0 * _ / _ + _ + 12.0 * _ - _ + _ * _ / _ == 87" << endl << endl;
	int a, b, c, d, e, f, g, h, i;
	int counter = 1;

	for (a = 1; a <= 9; a++) 
	{
		for (b = 1; b <= 9; b++) 
		{
			for (c = 1; c <= 9; c++) 
			{
				for (d = 1; d <= 9; d++) 
				{
					for (e = 1; e <= 9; e++) 
					{
						for (f = 1; f <= 9; f++) 
						{
							for (g = 1; g <= 9; g++) 
							{
								for (h = 1; h <= 9; h++) 
								{
									for (i = 1; i <= 9; i++) 
									{
										if ((a + 13.0 * b / c + d + 12.0 * e - f + g * h / i == 87)
											&& (a != b) && (a != c) && (a != d) && (a != e) && (a != f) && (a != g) && (a != h)
											&& (a != i) && (b != c) && (b != d) && (b != e) && (b != f) && (b != g) && (b != h)
											&& (b != i) && (c != d) && (c != e) && (c != f) && (c != g) && (c != h) && (c != i)
											&& (d != e) && (d != f) && (d != g) && (d != h) && (d != i) && (e != f) && (e != g)
											&& (e != h) && (e != i) && (f != g) && (f != h) && (f != i) && (g != h) && (g != i)
											&& (h != i) && (b % c == 0) && (g * h % i == 0))
										{
											cout << "Solution " << counter << '_' << a << b << c << d << e << f << g << h << i << endl;
											counter++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	cout << endl;
	system("pause");
	return 0;
}