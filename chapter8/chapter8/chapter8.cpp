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
	int option = 0;
	cout << "Input 1 for single print, and 2 for multiply print-->";
	while (cin>>option)
	{
		if (option == 1)
			print("single print!");
		else if (option == 2)
			print("multiply print!",1);
		else
			cout << "Quit with any letters or input 1 or 2 again-->";
	}
}

void ansTwo()
{
	CandyBar cb;
	setCandyBar(cb);
	printCandyBar(cb);
}

void ansThree()
{
	string st;
	cout << "Enter a string(q to quit): ";
	getline(cin,st);
	while (st.compare("q")!=0)
	{
		goBig(st);
		cout << st << endl;
		cout << "Next string(q to quit): ";
		getline(cin, st);
	}
}

void ansFour()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
}

void ansFive()
{
	int arr1[5] = { 1, 3, 9, 5, 2 };
	double arr2[5] = { 2.3, 4.9, 1.6, 9.4, 3.3 };
	cout << "The maxium number of { 1, 3, 9, 5, 2 } is " << compare(arr1) << endl;
	cout << "The maxium number of { 2.3, 4.9, 1.6, 9.4, 3.3 } is " << compare(arr2) << endl;
}

void ansSix()
{
	int arr1[6] = { 1, 3, 9, 5, 2, 7 };
	double arr2[4] = { 2.3, 4.9, 1.6, 9.4 };
	char* arr3[5] = { "abc", "abcde", "abcd", "abcdefg", "a" };
	cout << "The maxium number of { 1, 3, 9, 5, 2, 7 } is " << _compare(arr1,6) << endl;
	cout << "The maxium number of { 2.3, 4.9, 1.6, 9.4 } is " << _compare(arr2,4) << endl;
	cout << "The maxium number of { abc, abcde, abcd, abcdefg, a } is " << _compare(arr3,5) << endl;
}

void ansSeven()
{
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	double* pd[3];
	debts mr_E[3] =
	{
		{"Ima Wolfe",2400.0},
		{"Ura Foxe",1300.0},
		{"Iby Stout",1800.0}
	};
	for (int i = 0; i < 3; i++)
	{
		pd[i] = &mr_E[i].amount;
	}
	cout << "Template a Sum= " << SumArray(things, 6) << endl;
	cout << "Template b Sum= " << SumArray(pd, 3) << endl;
}

void ansEight(){}
void ansNine(){}
void ansTen(){}