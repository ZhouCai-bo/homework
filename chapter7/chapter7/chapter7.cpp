#include<iostream>
#include<cstring>
#include<string>
#include<array>
#include"functions.h"

using namespace std;

void ansOne();
void ansTwo();
void ansThree();
void ansFour();
void ansFive();
void ansSix();
void ansSeven();
void ansEight();
void ansNine();
void ansTen();

int main()
{
	cout << "Question number -->";
	int choice = 0;
	cin >> choice;
	cin.get();
	switch (choice)
	{
	case 1:ansOne(); break;
	case 2:ansTwo(); break;
	case 3:ansThree(); break;
	case 4:ansFour(); break;
	case 5:ansFive(); break;
	case 6:ansSix(); break;
	case 7:ansSeven(); break;
	case 8:ansEight(); break;
	case 9:ansNine(); break;
	case 10:ansTen(); break;
	}
	system("pause");
	return 0;
}

void ansOne()
{
	int a = 0, b = 0;
	cin >> a >> b;
	while (a != 0 && b != 0)
	{
		cout << "The average = " << dou_Avg(a, b) << endl;
		cin >> a >> b;
	}
}

void ansTwo()
{
	double scores[10] = { 0 };
	int cnt = int_Input(scores);
	vod_Print(scores, cnt);
	cout << "The average score is " << dou_Avg(scores, cnt) << endl;
}

void ansThree(){}
void ansFour(){}

void ansFive()
{
	int n = 0;
	cin >> n;
	cout << "The factorial of " << n << " is " << factorial(n) << endl;
}

void ansSix(){}
void ansSeven(){}
void ansEight(){}
void ansNine(){}

void ansTen()
{
	double a = 0, b = 0;
	while (cin >> a >> b)
	{
		cout << "The sum = " << calculate(a, b, add) << endl;
	}
}