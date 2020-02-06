
//#include"stdafx.h"
#include"Declaration.h"



using namespace std;

void ansOne();
void ansTwo();
void ansThree();
void ansFour();

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
	}
	system("pause");
	return 0;
}

void ansOne()
{
	using namespace Q1;
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Pinao Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;

	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
}

void ansTwo()
{
	using namespace Q2;
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Pinao Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;

	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
}

void ansThree()
{
	using namespace Q3;
	dmaABC *dmas[3];
	char *templabel = new char[50];
	int temprating;
	int tag;
	for (int i = 0; i < 3; i++)
	{
		cout << "Input No." << i + 1 << " DMA's label: ";
		cin >> templabel;
		cout << "Input No." << i + 1 << " DMA's rating: ";
		cin >> temprating;
		cout << "Input No." << i + 1 << " DMA's type( 1:baseDMA, 2:lackDMAm, 3:hasDMA ): ";
		while (cin >> tag && (tag != 1 && tag != 2 && tag != 3))
			cout << "Enter error! Input again: ";
		if (tag == 2)
		{
			cout << "Input No." << i + 1 << " DMA's color: ";
			char tempcolor[20];
			cin >> tempcolor;
			dmas[i] = new lackDMA(templabel, temprating, tempcolor);
		}
		else if (tag == 3)
		{
			cout << "Input No." << i + 1 << " DMA's style: ";
			char *tempstyle = new char[50];
			cin >> tempstyle;
			dmas[i] = new hasDMA(templabel, temprating, tempstyle);
		}
		else
		{
			dmas[i] = new baseDMA(templabel, temprating);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		dmas[i]->View();
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		delete dmas[i];
	}
}

void ansFour()
{
	
}
