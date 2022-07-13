// методы Ньютена-Котеса.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Locale>
#include <iostream>
#include <iomanip>
using namespace std;

double function(double x)
{
	return x * x * sqrt(1. + x * x * x);
}

double simpsonIntegral(double a, double b, int n) 
{
    const double h = (b-a)/n;

    double simpson_integral = 0;
    for(int i = 0; i < n; i++) 
	{
        const double x1 = a + i*h;
        const double x2 = a + (i+1)*h;

        simpson_integral += (x2-x1)/6.0*(function(x1)
			+ 4.0*function(0.5*(x1+x2)) + function(x2));
    }

    return simpson_integral;
}

double trapezoidalIntegral(double a, double b, int n) 
{
    const double h = (b-a)/n;

    double trapezoidal_integral = 0;
    for(int i = 0; i < n; i++) 
	{
        const double x1 = a + i*h;
        const double x2 = a + (i+1)*h;

        trapezoidal_integral += 0.5*(x2-x1)
			*(function(x1) + function(x2));
    }

    return trapezoidal_integral;
}

double rectangleIntegral(double a, double b, int n) 
{
    const double h = (b-a)/n;

    double rectangle_integral = 0;
    for(int i = 0; i < n ; i++) 
	{
        const double x1 = a + i * h;

        rectangle_integral += function(x1) ;
    }
	rectangle_integral = rectangle_integral * h;
    return rectangle_integral;
}

void _tmain()
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");
	system("color F0");
	  
	double a(0), b(1);
	double area1, area2, area3;
	int n (10);

	area1 = rectangleIntegral (a, b, n);
	area2 = trapezoidalIntegral (a, b, n);
	area3 = simpsonIntegral (a, b, n);

    cout << "Значение определенного интеграла:" 
		<< endl;
	cout << "Метод прямоугольников: "
		<< std::setprecision(16)
		<< area1 << endl;
	cout << "Метод трапеций: "
		<< std::setprecision(16)
		<< area2 << endl;
	cout << "Метод Симпсона: "
		<< std::setprecision(16)
		<< area3 << endl;
	system("pause");
}
