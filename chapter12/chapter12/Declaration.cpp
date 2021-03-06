// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "Declaration.h"
#include <iostream>


using namespace std;

//Q1
namespace Q1
{
	Cow::Cow()
	{
		strcpy_s(name, "default");
		hobby = new char[sizeof(name) + 1];
		strcpy_s(hobby, sizeof(name), name);
		weight = 0;
	}

	Cow::Cow(const char* nm, const char *no, double wt)
	{
		strncpy_s(name, nm, 19);
		hobby = new char[sizeof(no) + 1];
		strcpy_s(hobby, sizeof(name), name);
		weight = wt;
	}

	Cow::Cow(const Cow &c)
	{
		strcpy_s(name, c.name);
		hobby = new char[sizeof(c.hobby) + 1];
		strcpy_s(hobby, sizeof(name), name);
		weight = c.weight;
	}

	Cow::~Cow()
	{
		delete[] hobby;
	}

	Cow& Cow::operator=(const Cow & c)
	{
		strcpy_s(name, c.name);
		hobby = new char[sizeof(c.hobby) + 1];
		strcpy_s(hobby, sizeof(name), name);
		weight = c.weight;
	}

	void Cow::showCow() const
	{
		cout << "Name = " << this->name << endl;
		cout << "Hobby = " << this->hobby << endl;
		cout << "Weight = " << this->weight << endl;
	}
}


// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。
