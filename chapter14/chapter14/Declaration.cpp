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