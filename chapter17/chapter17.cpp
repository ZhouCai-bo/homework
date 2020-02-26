#include"Declaration.h"

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
	Q1::process1();
}

void ansTwo()
{
	Q2::process2();
}

void ansThree()
{
	Q3::process3();
}

void ansFour()
{
	Q4::process4();
}

void ansFive()
{
	Q5::process5();
}

void ansSix()
{

}

void ansSeven()
{

}

void ansEight()
{

}