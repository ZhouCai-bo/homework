#ifndef Declaration_h
#define Declaration_h
#include"stdafx.h"
#include<iostream>
#include<string>
#include<Stack>
#include<Array>
#include<Vector>

using std::string;
const int Len = 40;
static double Q5_payment = 0;
const int Size = 5;

//Q1
class Account
{
private:
	string s_name;
	string s_id;
	float s_banlance;

public:
	Account();
	Account(string name, string id, float banlance);
	void show() const;
	void save(float num);
	void withdraw(float num);

};

//Q2
class Person
{
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person(){ lname = "", fname[0] = '\0'; }
	Person(const string & ln, const char * fn = "Heyyou");
	void Show() const;
	void FormatShow() const;
};

//Q3
class golf
{

private:
	char fullname[Len];
	int handicap;
public:
	golf(char*, int);
	void setgolf(const golf&);
	void setgolf(char*, int);
	void showgolf();
};

//Q4
namespace SALES
{
	const int QUATERS = 4;
	class Sales
	{
	private:
		double sales[QUATERS];
		double average;
		double max;
		double min;
	public:
		Sales(const double*, int);
		void setSales(const double*, int);
		void setSales(const Sales s);
		void show();
	};
}
//Q5
struct customer
{
	char fullname[35];
	double payment;
	~customer()
	{
		std::cout << "Deconstruction " << std::endl;
		Q5_payment += payment;
	}
};
//customer import_customer(char*, double);
void import(customer&, char*, double a);
//Q6
class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showmove() const;
	Move add(const Move& m) const;          //第一个const表示形参不可修改，第二个表示干函数不能修改类的数据成员
	void reset(double a = 0, double b = 0);
};
//Q7
class plorg
{
private:
	char name[30];
	int CI;
public:
	plorg(char* n = "Plorga");
	void setCI(int c);
	void show();
};
//Q8
template<typename Item>
//不要使用除过int类型的参数。。。
class list
{
private:
	Item data[5];
	int currsize = 0;
public:
	list(){}
	bool isEmpty();
	bool isFull();
	void addItem(Item);
	//将函数作为参数调用函数，该函数访问列表中的每一个数据并使用参数函数处理
	//在main函数中，可以传递不同的函数作为参数已达到不同的处理
	void visit(void (*pf)(Item &));
};
void show(int&);
void setValue(int&);
#endif

