
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
	const int SIZE = 5;

	using namespace	Q3;
	QueueTp<Worker *> qw(5);

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\nw:waiter  s:singer  t:singing waiter  q;quit\n";
		cin >> choice;
		while (!strchr("wstq", choice))
		{
			cout << "Please enter a w,s,t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		Worker *w = new Waiter();
		switch (choice)
		{
		case 'w':delete w;
			w = new Waiter();
			w->Set();
			qw.push(w); 
			break;
		case 's':delete w; 
			w = new Singer();
			w->Set();
			qw.push(w); 
			break;
		case 't':delete w; 
			w = new SingerWaiter();
			w->Set();
			qw.push(w); 
			break;
		}
		cin.get();
	}
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		Worker *w;
		qw.pop(w);
		w->Show();
		delete w;
	}
}

void ansFour()
{
	const int SIZE = 5;

	using namespace	Q4;
	Person *ps[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the person category:\ng:gunsliner  p:pokerplayer  b:baddude  q;quit\n";
		cin >> choice;
		while (!strchr("gpbq", choice))
		{
			cout << "Please enter a g,p,b, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'g':ps[ct] = new Gunslinger();
			ps[ct]->Set();
			break;
		case 'p':ps[ct] = new PokerPlayer();
			ps[ct]->Set();
			break;
		case 'b':ps[ct] = new BadDude();
			ps[ct]->Set();
			break;
		}
		cin.get();
	}
	cout << "\nHere is your friends:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		if (!ps[i])
			continue;
		cout << endl;
		ps[i]->Show();
	}
	for (i = 0; i < ct; i++)
	{
		delete ps[i];
	}
}

void ansFive()
{
	using namespace Q5;
	employee em("Trip", "Harrris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	manager ma("Amrophia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	highfink hf(ma, "Curly Kew");
	hf.ShowAll();
	cout << "Press a key for next phase:\n";
	cin.get();
	highfink hf2;
	hf2.SetAll();

	cout << "Using an abstr_amp * pointer:\n";
	abstr_amp *tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();
}

