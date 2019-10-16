#include<iostream>
#include<string>
#include<cctype>
using namespace std;

struct CandyBar
{
	string brand;
	double quilt;
	int heat;
};

struct stringy
{
	char* str;
	int ct;
};

struct debts
{
	char name[50];
	double amount;
};

//Question one
void print(char*);
void print(char*, int);
//Question two
void setCandyBar(CandyBar&,string st="Millennium Munch", double a=2.85, int b=350);
void printCandyBar(const CandyBar&);
//Question three
void goBig(string&);
//Question four
void set(stringy&, const char*);
void show(const char*, int a = 1);
void show(const stringy&, int a = 1);
//Question five
template <typename T>
T compare(T arr[5])
{
	T max = arr[0];
	for (int i = 0; i < 5; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}
//Question six
//模板函数的声明和定义不能分开，同时置于头文件
template <typename T>
T _compare(T arr[],int a)
{
	T max = arr[0];
	for (int i = 0; i < a; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}
//模板函数的显式具体化声明置于头文件，实现置于.cpp文件
template<> char* _compare<char*>(char* arr[], int a);
//Question seven
template<typename T>
T SumArray(T arr[], int a)
{
	T sum = arr[0];
	for (int i = 1; i < a; i++)
	{
		sum += arr[i];
	}
	return sum;
}
template<typename T>
T SumArray(T* arr[], int a)
{
	T sum = *arr[0];
	for (int i = 1; i < a; i++)
	{
		sum += *arr[i];
	}
	return sum;
}
