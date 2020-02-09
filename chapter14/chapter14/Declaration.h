#ifndef DECLARATION_H
#define DECLARATION_H

#include<iostream>
#include<valarray>
#include<string>

using namespace std;

namespace Q1
{
	class Wine
	{
	private:
		string _name;
		pair<valarray<int>, valarray<int>> _p;
		int _year;

	public:
		Wine(const char *l, int y, const int yr[], const int bot[]);
		Wine(const char *l, int y);
		void GetBottles();
		string & Label() {return _name; }
		int sum();
		void show();
	};
}

namespace Q2
{
	class Wine :private string, private pair<valarray<int>,valarray<int>>
	{
		typedef pair<valarray<int>, valarray<int>> pairArr;

	private:
		int _year;

	public:
		Wine(const char *l, int y, const int yr[], const int bot[]);
		Wine(const char *l, int y);
		void GetBottles();
		const string & Label();
		int sum();
		void show();
	};
}

#endif