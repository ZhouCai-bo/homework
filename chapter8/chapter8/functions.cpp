#include"functions.h"


int printCallCnt = 0;
//Question one
void print(char* ch)
{
	cout << ch << endl;
}
void print(char* ch, int a)
{
	++printCallCnt;
	for (int i = 0; i < printCallCnt; i++)
	{
		cout << ch << endl;
	}
}
//Question two
void setCandyBar(CandyBar& cd,string br, double ql, int ht)
{
	cd.brand = br;
	cd.quilt = ql;
	cd.heat = ht;
}
void printCandyBar(const CandyBar& cb)
{
	cout << "Brand: " << cb.brand << endl;
	cout << "Qulity: " << cb.quilt << endl;
	cout << "Heat: " << cb.heat << endl;
}
//Question three
void goBig(string& st)
{
	for (char& ch:st)
	{
		ch = toupper(ch);
	}
}
//Question four
void set(stringy& sty, const char* str)
{
	//先分配空间，后赋值！！！
	sty.ct = strlen(str);
	sty.str = new char[sty.ct];
	strcpy(sty.str, str);
}
void show(const stringy& sty, int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << sty.str << endl;
	}
}
void show(const char* ch, int a)
{
	for (int i = 0; i < a; i++)
	{
		cout << ch << endl;
	}
}
//Question five
template<> char* _compare<char*>(char* arr[], int a)
{
	char* max = arr[0];
	for (int i = 0; i < a; i++)
	{
		if (strlen(arr[i])>strlen(max))
		{
			max = arr[i];
		}
	}
	return max;
}
