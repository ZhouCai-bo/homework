
#include"Declaration.h"

//using namespace std;

void ansOne();
void ansTwo();
void ansThree();
void ansFour();
void ansFive();

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
	}
	system("pause");
	return 0;
}

void ansOne()
{
	using namespace Q1;

	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.show();
	cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;
	cout << "Bye\n";
}

void ansTwo()
{
	using namespace Q2;

	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.show();
	cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;
	cout << "Bye\n";
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

