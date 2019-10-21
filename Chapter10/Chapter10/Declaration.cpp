
#include"stdafx.h"
#include"Declaration.h"

using std::cout;
using std::endl;

//Q1
Account::Account(string name, string id, float banlance)
{
	s_name = name;
	s_id = id;
	s_banlance = banlance;
}
void Account::show() const
{
	cout << "AccName: " << s_name << " AccID: " << s_id << " AccBanlance:" << s_banlance << endl;
}
void Account::save(float num)
{
	s_banlance += num;
	cout << num << " saved successfully!" << endl;
}
void Account::withdraw(float num)
{
	if (num > s_banlance)
	{
		cout << "Not enough banlance!" << endl;
	}
	else
	{
		s_banlance -= num;
		cout << num << " withdrawed successfully!" << endl;
	}
}

//Q2
Person::Person(const string & ln, const char * fn )
{
	lname = ln;
	strcpy_s(fname, fn);
}
void Person::Show() const
{
	cout << fname + lname << endl;
}
void Person::FormatShow() const
{
	cout << lname + "," + fname << endl;
}

//Q3
golf::golf(char* ch, int i)
{
	strcpy_s(fullname, ch);
	handicap = i;
}
void golf::setgolf(const golf& g)
{
	strcpy_s(fullname, g.fullname);
	handicap = g.handicap;
}
void golf::setgolf(char* ch, int i)
{
	strcpy_s(fullname, ch);
	handicap = i;
}
void golf::showgolf()
{
	cout << "fullname = " << fullname << endl;
	cout << "handicap = " << handicap << endl;
}

//Q4
SALES::Sales::Sales(const double* ar, int n)
{
	max = ar[0];
	min = ar[0];
	int i = 0;
	for ( ; i < 4 || i < n; i++)
	{
		sales[i] = ar[i];
		average += ar[i];
		if (ar[i] < min)
		{
			min = ar[i];
		}
		if (ar[i]>max)
		{
			max = ar[i];
		}
	}
	if (i <= 4)
	{
		for (int j = i - 1; j < 4; j++)
		{
			sales[j] = 0;
		}
	}
	average /= n;
}
void SALES::Sales::setSales(const double* ar, int n)
{
	max = ar[0];
	min = ar[0];
	for (int i = 0; i < 4 || i < n; i++)
	{
		sales[i] = ar[i];
		average += ar[i];
		if (ar[i] < min)
		{
			min = ar[i];
		}
		if (ar[i]>max)
		{
			max = ar[i];
		}
	}
	average /= n;
}
void SALES::Sales::setSales(const Sales s)
{
	max = s.sales[0];
	min = s.sales[0];
	for (int i = 0; i < 4; i++)
	{
		sales[i] = s.sales[i];
		average += s.sales[i];
	}
	average = s.average;
	max = s.max;
	min = s.min;
}
void SALES::Sales::show()
{
	for (int i = 0; i < 4; i++)
	{
		cout << sales[i] << " ";
		cout << endl;
	}
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
}
//Q5
//这样构造结构体会创建临时结构，临时结构在析构时会使全局变量自加
//customer import_customer(char* ch, double p)
//{
//	customer c;
//	strcpy_s(c.fullname, ch);
//	c.payment = p;
//	return c;
//}
void import(customer& c, char* ch, double a)
{
	strcpy_s(c.fullname, ch);
	c.payment = a;
}
//Q6
Move::Move(double a, double b)
{
	x = a;
	y = b;
}
void Move::showmove() const
{
	cout << "x = " << x << " , y = " << y << endl;
}
Move Move::add(const Move& m) const
{
	Move newm(x + m.x, y + m.y);
	return newm;

}
void Move::reset(double a, double b)
{
	x = a;
	y = b;
}
//Q7
plorg::plorg(char* n)
{
	strcpy_s(name, n);
	CI = 50;
}
void plorg::setCI(int c)
{
	CI = c;
}
void plorg::show()
{
	cout << "Plorg name = " << name << " CI = " << CI << endl;
}
//Q8
void list<int>::visit(void(*pf)(int &))
{
	(*pf)(data[0]);
}
void show(int &i)
{
	cout << i << endl;
}
void setValue(int &i)
{
	i += 5;
}
bool list<int>::isEmpty()
{
	if (!currsize)
		return true;
	return false;
}
bool list<int>::isFull()
{
	if (currsize == Size)
		return true;
	return false;
}
void list<int>::addItem(int i)
{
	if (isFull())
	{
		cout << "The list is full with 5 elements, can not add more element!" << endl;
		return;
	}
	data[currsize] = i;
	currsize++;
}