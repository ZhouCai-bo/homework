#ifndef DECLARATION_H
#define DECLARATION_H

#include<iostream>
#include<valarray>
#include<string>
#include<list>
#include<ctime>

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

namespace Q3
{
	class Worker
	{
	private:
		string fullname;
		long id;
	protected:
		virtual void Data() const;
		virtual void Get();
	public:
		Worker() :fullname("no one"), id(0L){}
		Worker(const string &s, long n) :fullname(s), id(n){}
		virtual ~Worker() = 0;
		virtual void Set() = 0;
		virtual void Show() const = 0;
	};
	class Waiter :virtual public Worker
	{
	private:
		int panacha;
	protected:
		void Data() const;
		void Get();
	public:
		Waiter() :Worker(), panacha(0){}
		Waiter(const string &s, long n, int p = 0) :Worker(s, n), panacha(p){}
		Waiter(const Worker &wk, int p = 0) :Worker(wk), panacha(p){}
		void Set();
		void Show() const;
	};
	class Singer :virtual public Worker
	{
	protected:
		enum{ other, alto, contralto, soprano, bass, baritone, tenor };
		enum{ Vtypes = 7 };
		void Data() const;
		void Get();
	private:
		static char *pv[Vtypes];
		int voice;
	public:
		Singer() :Worker(), voice(other){}
		Singer(const string &s, long n, int v = other) :Worker(s, n), voice(v){}
		Singer(const Worker &wk, int v = other) :Worker(wk), voice(v){}
		void Set();
		void Show() const;
	};
	class SingerWaiter :public Singer, public Waiter
	{
	protected:
		void Data() const;
		void Get();
	public:
		SingerWaiter(){}
		SingerWaiter(const string &s, long n, int p = 0, int v = other) :Worker(s, n), Waiter(s, n, p), Singer(s, n, v){}
		SingerWaiter(const Worker &wk, int p = 0, int v = other) :Worker(wk), Waiter(wk, p), Singer(wk, v){}
		SingerWaiter(const Waiter &wt, int v = other) :Worker(wt), Waiter(wt), Singer(wt, v){}
		SingerWaiter(const Singer &wt, int p = 0) :Worker(wt), Waiter(wt, p), Singer(wt){}
		void Set();
		void Show() const;
	};

	template<typename T>
	class QueueTp
	{
	private:
		list<T> l;
		int size = 0;
		const int maxSize;
	public:
		QueueTp() :maxSize(0){}
		QueueTp(int maxsize) :maxSize(maxsize){}
		//template<typename TT>
		bool push(T t)
		{
			if (isfull())
				return false;
			l.push_back(t);
			size++;
		}
		bool pop(T &t)
		{
			if (isempty())
				return false;
			t = l.front();
			l.pop_front();
			size--;
			return true;
		}
		bool isempty(){ return size == 0; }
		bool isfull(){ return size == maxSize; }
		T & rear(){ return l.back; }
	};
}

namespace Q4
{
	class Person
	{
	protected:
		string firstName;
		string lastName;
	public:
		Person(){}
		virtual void Show();
		virtual void Set();
	};

	class Gunslinger :virtual public Person
	{
	private:
		int craw;
		double time;
	protected:
		double Draw(){ return time; }
	public:
		Gunslinger() :Person(){}
		void Show();
		void Set();
	};

	class PokerPlayer :virtual public Person
	{
	protected:
		int Draw();
	public:
		PokerPlayer() :Person(){}
		void Show(){ Person::Show(); }
		void Set(){ Person::Set(); }
	};

	class BadDude: public Gunslinger, public PokerPlayer
	{
	public:
		BadDude() :Person(), Gunslinger(), PokerPlayer(){}
		double Gdraw();
		int Cdraw();
		void Show();
		void Set();
	};
}

namespace Q5
{
	class abstr_amp
	{
	private:
		string fname;
		string lname;
		string job;
	public:
		abstr_amp(){}
		abstr_amp(const string &fn,string ln,const string &j);
		virtual void ShowAll() const;
		virtual void SetAll();
		friend ostream & operator<<(ostream &os, const abstr_amp &e);
		virtual ~abstr_amp() = 0;
	};

	class employee :public abstr_amp
	{
	public:
		employee(){}
		employee(const string &fn, const string &ln, const string &j);
		virtual void ShowAll() const;
		virtual void SetAll();
	};

	class manager :virtual public abstr_amp
	{
	private:
		int inchargeof;
	protected:
		int InChargeOf() const{ return inchargeof; }
		int & InChargeOf(){ return inchargeof; }
	public:
		manager(){}
		manager(const string &fn, const string &ln, const string &j, int ico = 0);
		manager(const abstr_amp &e, int ico);
		manager(const manager &m);
		virtual void ShowAll() const;
		virtual void SetAll();
	};

	class fink :virtual public abstr_amp
	{
	private:
		string reportsto;
	protected:
		const string ReportsTo() const{ return reportsto; }
		string & ReportsTo(){ return reportsto; }
	public:
		fink(){}
		fink(const string &fn, const string &ln, const string &j, const string &rpo);
		fink(const abstr_amp &e, const string &rpo);
		fink(const fink &e);
		virtual void ShowAll() const;
		virtual void SetAll();
		void Set();
	};

	class highfink :public manager, public fink
	{
	public:
		highfink(){}
		highfink(const string &fn, const string &ln, string &j, const string &rpo, int ico);
		highfink(const abstr_amp &e, const string &rpo, int ico);
		highfink(const manager &m, const string &rpo);
		highfink(const highfink &h);
		virtual void ShowAll() const;
		virtual void SetAll();
	};
}

#endif