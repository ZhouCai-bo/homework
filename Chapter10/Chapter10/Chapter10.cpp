#include"stdafx.h"

//#include<iostream>
//#include<string>
//#include<array>
//#include<vector>
#include"Declaration.h"
//#include"Declaration.cpp"


using namespace std;

void ansOne();
void ansTwo();
void ansThree();
void ansFour();
void ansFive();
void ansSix();
void ansSeven();
void ansEight();


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
	}
	system("pause");
	return 0;
}

void ansOne()
{
	Account Tom("Tom", "001", 1000);
	Account Jerry("Jerry", "002", 1500);
	Tom.show();
	Jerry.show();
	Tom.save(50.5);
	Jerry.save(20);
	Tom.show();
	Jerry.show();
	Tom.withdraw(500);
	Jerry.withdraw(2000);
	Tom.show();
	Jerry.show();
}

void ansTwo()
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimiwiddy", "Sam");
	one.Show();
	cout << endl;
	one.FormatShow();
	two.Show();
	cout << endl;
	two.FormatShow();
	three.Show();
	cout << endl;
	three.FormatShow();
}

void ansThree()
{
	golf g0("test0", 5);
	golf g1("test1", 10);
	g0.showgolf();
	g1.showgolf();
	cout << "将test1复制到test0后" << endl;
	g0.setgolf(g1);
	g1.showgolf();
}

void ansFour()
{
	double ar0[] = { 1, 2, 3, 4 };
	double ar1[] = { 2, 4, 6 };
	SALES::Sales s0(ar0, 4);
	SALES::Sales s1(ar1, 3);
	s0.show();
	s1.show();
	cout << "复制后" << endl;
	s0.setSales(s1);
	s0.show();
	s1.show();
}

void ansFive()
{
	stack<customer> sk;
	customer c[4];
	import(c[0], "Jack", 5);
	import(c[1], "Rose", 10);
	import(c[2], "Tom", 25);
	import(c[3], "Jerry", 15);

	sk.push(c[0]);
	sk.push(c[1]);
	sk.push(c[2]);
	sk.push(c[3]);
	cout << "Before pop, payment = " << Q5_payment << endl;
	sk.pop();
	cout << "First pop, payment = " << Q5_payment << endl;
	sk.pop();
	cout << "Second pop, payment = " << Q5_payment << endl;
	sk.pop();
	cout << "Third pop, payment = " << Q5_payment << endl;
	sk.pop();
	cout << "Forth pop, payment = " << Q5_payment << endl;
	//会弹出八次析构提示，原因未知
}

void ansSix()
{
	Move m1, m2(3, 3), m3(5, 7);
	cout << "After initialize." << endl;
	m1.showmove();
	m2.showmove();
	m3.showmove();
	cout << "After m2 + m3" << endl;
	m2.add(m3).showmove();
	cout << "Reset m2, m3" << endl;
	m2.reset();
	m3.reset();
	m1.showmove();
	m2.showmove();
	m3.showmove();
}

void ansSeven()
{
	vector<plorg> a{ { "Jack" }, { "Rose" }, {} };
	cout << "Ater initialized" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		a[i].show();
	}
	cout << "After reset" << endl;
	a[1].setCI(20);
	a[0].setCI(100);
	for (int i = 0; i < a.size(); i++)
	{
		a[i].show();
	}
}

void ansEight()
{
	list<int> l;
	if (l.isEmpty()){ cout << "List is empty."<<endl; }
	l.addItem(1);
	l.addItem(2);
	l.addItem(3);
	l.addItem(4);
	l.addItem(5);
	l.addItem(6);
	void (*pf)(int&);
	void(*pf1)(int&);
	pf = show;
	l.visit(pf);
	pf1 = setValue;
	l.visit(pf1);
	l.visit(pf);
}