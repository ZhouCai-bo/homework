#ifndef DECLARATION_H
#define DECLARATION_H

#include<iostream>

using namespace std;

namespace Q1
{
	class Cd
	{
	private:
		char performers[50];
		char label[20];
		int selections;
		double playtime;
	public:
		Cd(char *s1, char *s2, int n, double x);
		Cd(const Cd &d);
		Cd();
		//~Cd();
		virtual void Report() const;
		Cd & operator=(const Cd &d);
	};

	class Classic :public Cd
	{
	private:
		char main[100];
	public:
		Classic(char *s1, char *s2, char *s3, int n, double x);
		Classic();
		//Classic & operator=(const Classic & c);
		virtual void Report() const;
	};

	void Bravo(const Cd & disk);
}

namespace Q2
{
	class Cd
	{
	private:
		char *performers;
		char *label;
		int selections;
		double playtime;
	public:
		Cd(char *s1, char *s2, int n, double x);
		Cd(const Cd &d);
		Cd();
		virtual ~Cd();
		virtual void Report() const;
		Cd & operator=(const Cd &d);
	};

	class Classic :public Cd
	{
	private:
		char *main;
	public:
		Classic(char *s1, char *s2, char *s3, int n, double x);
		Classic();
		~Classic();
		Classic & operator=(const Classic & c);
		virtual void Report() const;
	};

	void Bravo(const Cd & disk);
}

namespace Q3
{
	class dmaABC
	{
	private:
		char *label;
		int rating;
	protected:
		char * getLabel(){ return label; }
		int getRating(){ return rating; }
	public:
		dmaABC(){};
		dmaABC(char *c1, int i);
		virtual ~dmaABC();
		virtual void View() = 0;
	};

	class baseDMA :public dmaABC
	{
	public:
		baseDMA(){};
		baseDMA(char *c1, int i);
		virtual void View();
	};

	class lackDMA :public dmaABC
	{
	private:
		char color[40];
	public:
		lackDMA(){};
		lackDMA(char *c1, int i, char *c2);
		virtual void View();

	};

	class hasDMA :public dmaABC
	{
	private:
		char *style;
	public:
		hasDMA(){};
		hasDMA(char *c1, int i, char *c2);
		~hasDMA();
		virtual void View();
	};
}

namespace Q4
{
	class Port
	{
	private:
		char *brand;
		char style[20];
		int bottles;
	public:
		Port(const char *br = "none", const char *st = "none", int b = 0);
		Port(const Port &p);
		virtual ~Port(){ delete[] brand; }
		Port & operator=(const Port &p);
		Port & operator+=(int b);
		Port & operator-=(int b);
		int BottleCount() const;
		virtual void show() const;
		friend ostream & operator<<(ostream &os, const Port &p);
	};

	class VintagePort :public Port
	{
	private:
		char *nickname;
		int year;
	public:
		VintagePort();
		VintagePort(const char *br, int b, const char *nn, int y);
		VintagePort(const VintagePort &vp);
		~VintagePort(){ delete[] nickname; }
		VintagePort & operator=(const VintagePort & vp);
		void show() const;
		friend ostream & operator<<(ostream &os, VintagePort &vp);
	};
}

#endif