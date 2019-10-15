#include<iostream>
#include"functions.h"
using namespace std;
#pragma once

double dou_Avg(int a, int b)
{
	return 2.0*a*b / (a + b);
}
int int_Input(double* arr)
{
	int cnt = 0;
	double in = 0.0;
	cout << "Input your score and end with any letter." << endl;
	while (std::cin >> in && cnt < 10)
	{
		arr[cnt] = in;
		++cnt;
	}
	return cnt;
}
void vod_Print(double* arr, int cnt)
{
	cout << "Here is you scores:" << endl;
	for (int i = 0; i < cnt; i++)
	{
		cout << "NO." << i + 1 << "\t";
	}
	cout << endl;
	for (int i = 0; i < cnt; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
double dou_Avg(double* arr, int cnt)
{
	double sum = 0.0;
	for (int i = 0; i < cnt; i++)
	{
		sum += arr[i];
	}
	return sum / cnt;
}
int factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n*factorial(n - 1);
}
double calculate(double a, double b, double(*fptr)(double, double))
{
	return (*fptr)(a, b);
}
double add(double a, double b)
{
	return a + b;
}