

#include "Declaration.h"
#include "Declaration.cpp"

void ansOne();
void ansTwo();
void ansThree();
void ansFour();
void ansFive();
void ansSix();
void ansSeven();



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

	}
	system("pause");
	return 0;
}

void ansOne()
{
	using namespace Q1;
	Cow c1;
	Cow c2("Jack", "Eating", 75);
	Cow c3(c2);
	c1.showCow();
	c2.showCow();
	c3.showCow();
	c1 = c3;
	c1.showCow();
}

void ansTwo()
{
}

void ansThree()
{
	
}

void ansFour()
{
	
}

void ansFive()
{
	
}

void ansSix()
{
	
}

void ansSeven()
{
	
}



