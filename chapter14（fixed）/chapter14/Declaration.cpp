#include "Declaration.h"

namespace Q1
{
	Wine::Wine(const char *l, int y, const int yr[], const int bot[])
	{
		_name = l;
		_year = y;
		_p.first.resize(_year);
		_p.second.resize(_year);
		for (int i = 0; i < _year; i++)
		{
			_p.first[i] = yr[i];
			_p.second[i] = bot[i];
		}
	}
	Wine::Wine(const char *l, int y)
	{
		_name = l;
		_year = y;
		_p.first.resize(_year);
		_p.second.resize(_year);
	}
	void Wine::GetBottles()
	{
		cout << "Enter " << _name << " data for " << _year << " year(s)" << endl;
		for (int i = 0; i < _year; i++)
		{
			cout << "Enter year ";
			cin >> _p.first[i];
			cout << "Enter bottles for that year: ";
			cin >> _p.second[i];
		}
		
	}
	int Wine::sum()
	{
		return _p.second.sum();
	}
	void Wine::show()
	{
		cout << "Wine: " << _name << endl;
		cout << "\tYear\tBottles"  << endl;
		for (int i = 0; i < _year; i++)
		{
			cout << "\t" << _p.first[i] << "\t" << _p.second[i] << endl;
		}
		
	}
}

namespace Q2
{
	Wine::Wine(const char *l, int y, const int yr[], const int bot[]) :string(l)
	{
		_year = y;
		pairArr::first.resize(_year);
		pairArr::second.resize(_year);
		for (int i = 0; i < _year; i++)
		{
			pairArr::first[i] = yr[i];
			pairArr::second[i] = bot[i];
		}
	}
	Wine::Wine(const char *l, int y) : string(l)
	{
		_year = y;
		pairArr::first.resize(_year);
		pairArr::second.resize(_year);
	}
	void Wine::GetBottles()
	{
		cout << "Enter " << (const string &)*this << " data for " << _year << " year(s)" << endl;
		for (int i = 0; i < _year; i++)
		{
			cout << "Enter year ";
			cin >> pairArr::first[i];
			cout << "Enter bottles for that year: ";
			cin >> pairArr::second[i];
		}
	}
	const string & Wine::Label()
	{
		return (const string &)*this;
	}
	int Wine::sum()
	{
		return pairArr::second.sum();
	}
	void Wine::show()
	{
		cout << "Wine: " << (const string &)*this << endl;
		cout << "\tYear\tBottles" << endl;
		for (int i = 0; i < _year; i++)
		{
			cout << "\t" << pairArr::first[i] << "\t" << pairArr::second[i] << endl;
		}
	}
}

namespace Q3
{
	//worker methods
	Worker::~Worker(){}
	void Worker::Data() const
	{
		cout << "Name: " << fullname << endl;
		cout << "Employee ID: " << id << endl;

	}
	void Worker::Get()
	{
		cin.get();
		getline(cin, fullname);
		cout << "Enter Worker's ID: ";
		cin >> id;
		while (cin.get()!='\n')
		{
			continue;
		}
	}

	//waiter method
	void Waiter::Set()
	{
		cout << "Enter waiter's name:";
		Worker::Get();
		Get();
	}
	void Waiter::Show() const
	{
		cout << "Category: waiter\n";
		Worker::Data();
		Data();
	}
	void Waiter::Data() const
	{
		cout << "Panacha rating: " << panacha << endl;
	}
	void Waiter::Get()
	{
		cout << "Enter waiter's panacha rating: ";
		cin >> panacha;
		while (cin.get() != '\n')
			continue;
	}
	//Singer methods
	char *Singer::pv[Singer::Vtypes] = { "other", "alto", "contrallo", "soprano", "bass", "baritone", "tenor" };
	void Singer::Set()
	{
		cout << "Enter singer's name: ";
		Worker::Get();
		Get();
	}
	void Singer::Show() const
	{
		cout << "Categoory: singer\n";
		Worker::Data();
		Data();
	}
	void Singer::Data() const
	{
		cout << "Vocal range: " << pv[voice] << endl;
	}
	void Singer::Get()
	{
		cout << "Enter number for singer's vocal range:\n";
		int i;
		for (i = 0; i < Vtypes; i++)
		{
			cout << i << ": " << pv[i] << "  ";
			if (i % 4 == 3)
				cout << endl;
		}
		if (i % 4 != 0)
			cout << '\n';
		cin >> voice;
		while (cin.get() != '\n')
			continue;
	}
	//SingerWaiter
	void SingerWaiter::Data() const
	{
		Singer::Data();
		Waiter::Data();
	}
	void SingerWaiter::Get()
	{
		Waiter::Get();
		Singer::Get();
	}
	void SingerWaiter::Set()
	{
		cout << "Enter singing waiter's name: ";
		Worker::Get();
		Get();
	}
	void SingerWaiter::Show() const
	{
		cout << "Catagory: singing waiter\n";
		Worker::Data();
		Data();
	}
}

namespace Q4
{
	void Person::Show()
	{
		cout << "Name: " << Person::firstName << " " << Person::lastName << endl;
	}
	void Person::Set()
	{
		cout << "Enter firstname: ";
		cin >> firstName;
		cout << "Enter lastname: ";
		cin >> lastName;
	}
	void Gunslinger::Show()
	{
		Person::Show();
		cout << "Craws: " << craw << endl;
	}
	void Gunslinger::Set()
	{
		Person::Set();
		cout << "Enter craws: ";
		cin >> craw;
		cout << "Enter time for gun pulling off: ";
		cin >> time;
	}

	int PokerPlayer::Draw()
	{
		srand(time(0));
		return rand() % 52 + 1;
	}
	double BadDude::Gdraw()
	{
		return Gunslinger::Draw();
	}
	int BadDude::Cdraw()
	{
		return PokerPlayer::Draw() + 1 <= 52 ? PokerPlayer::Draw() : 1;
	}
	void BadDude::Show()
	{
		Gunslinger::Show();
		cout << "Draw gun: " << Gdraw() << endl;
		int i = Cdraw();
		if (0 < i <= 13)
			cout << "Next poker: " << "Spade " << i << endl;
		else if (13 < i <= 26)
			cout << "Next poker: " << "Heart " << i - 13 << endl;
		else if (26 < i <= 39)
			cout << "Next poker: " << "Diamond " << i - 26 << endl;
		else if (39 < i <= 52)
			cout << "Next poker: " << "Club " << i - 39 << endl;
	}
	void BadDude::Set()
	{
		Gunslinger::Set();
	}
}

namespace Q5
{
	//abstr_amp methods
	abstr_amp::abstr_amp(const string &fn, string ln, const string &j)
	{
		fname = fn;
		lname = ln;
		job = j;
	}
	void abstr_amp::ShowAll() const
	{
		cout << "Firstname: " << fname << endl;
		cout << "Lastname: " << lname << endl;
		cout << "Job: " << job << endl;
	}
	void abstr_amp::SetAll()
	{
		cout << "Enter firstname: ";
		cin >> fname;
		cout << "Enter lastname: ";
		cin >> lname;
		cout << "Enter job: ";
		cin >> job;
	}
	ostream & operator<<(ostream &os, const abstr_amp &e)
	{
		os << "Firstname: " << e.fname << endl;
		os << "Lastname: " << e.lname << endl;
		return os;
	}
	abstr_amp::~abstr_amp(){}
	//employee methods
	employee::employee(const string &fn, const string &ln, const string &j) :abstr_amp(fn, ln, j)
	{}
	void employee::ShowAll() const
	{
		abstr_amp::ShowAll();
	}
	void employee::SetAll()
	{
		abstr_amp::SetAll();
	}
	//manager methods
	manager::manager(const string &fn, const string &ln, const string &j, int ico) :abstr_amp(fn, ln, j)
	{
		inchargeof = ico;
	}
	manager::manager(const abstr_amp &e, int ico) : abstr_amp(e)
	{
		inchargeof = ico;
	}
	manager::manager(const manager &m) : abstr_amp(m)
	{
		inchargeof = m.inchargeof;
	}
	void manager::ShowAll() const
	{
		abstr_amp::ShowAll();
		cout << "Incharge of: " << inchargeof<< endl;
	}
	void manager::SetAll()
	{
		abstr_amp::SetAll();
		cout << "Enter inchargeof: ";
		cin >> inchargeof;
	}
	//fink methods
	fink::fink(const string &fn, const string &ln, const string &j, const string &rpo) :abstr_amp(fn, ln, j)
	{
		reportsto = rpo;
	}
	fink::fink(const abstr_amp &e, const string &rpo) : abstr_amp(e)
	{
		reportsto = rpo;

	}
	fink::fink(const fink &e) : abstr_amp(e)
	{
		reportsto = e.reportsto;
	}
	void fink::ShowAll() const
	{
		abstr_amp::ShowAll();
		cout << "Reports to: " << reportsto << endl;
	}
	void fink::SetAll()
	{
		abstr_amp::SetAll();
		cout << "Enter reportsto: ";
		cin >> reportsto;
	}
	void fink::Set()
	{
		cout << "Enter reportsto: ";
		cin >> reportsto;
	}
	//highfink methods
	highfink::highfink(const string &fn, const string &ln, string &j, const string &rpo, int ico) 
		: abstr_amp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
	{}
	highfink::highfink(const abstr_amp &e, const string &rpo, int ico)
		: abstr_amp(e), manager(e, ico), fink(e, rpo)
	{}
	highfink::highfink(const manager &m, const string &rpo)
		: abstr_amp(m), manager(m), fink(m, rpo)
	{}
	highfink::highfink(const highfink &h)
		: abstr_amp(h), manager(h), fink(h)
	{}
	void highfink::ShowAll() const
	{
		abstr_amp::ShowAll();
		cout << "Incharge of: " << manager::InChargeOf() << endl;
		cout << "Reports to: " << fink::ReportsTo() << endl;
	}
	void highfink::SetAll()
	{
		manager::SetAll();
		fink::Set();
	}
}