#include"Declaration.h"

namespace Q1
{
	void Bravo(const Cd & disk)
	{
		disk.Report();
	}

	Cd::Cd(char *s1, char *s2, int n, double x)
	{
		strcpy_s(performers, s1);
		strcpy_s(label, s2);
		selections = n;
		playtime = x;
	}
	Cd::Cd(const Cd &d)
	{
		strcpy_s(performers, d.performers);
		strcpy_s(label, d.label);
		selections = d.selections;
		playtime = d.playtime;
	}
	Cd::Cd()
	{
	}
	void Cd::Report() const
	{
		cout << "Cd performers: " << performers << endl;
		cout << "     Cd label: " << label << endl;
		cout << "Cd selections: " << selections << endl;
		cout << "  Cd playtime: " << playtime << endl;
	}
	Cd & Cd::operator=(const Cd &d)
	{
		strcpy_s(performers, d.performers);
		strcpy_s(label, d.label);
		selections = d.selections;
		playtime = d.playtime;
		return *this;
	}

	Classic::Classic(char *s1, char *s2, char *s3, int n, double x) :Cd(s2,s3,n,x)
	{
		strcpy_s(main, s1);
	}
	void Classic::Report() const
	{
		Cd::Report();
		cout << " Cd main work: " << main << endl;
	}
	Classic::Classic()
	{
	}
}

namespace Q2
{
	void Bravo(const Cd & disk)
	{
		disk.Report();
	}

	Cd::Cd(char *s1, char *s2, int n, double x)
	{
		performers = new char[strlen(s1) + 1];
		strcpy_s(performers, strlen(s1) + 1, s1);
		label = new char[strlen(s2 + 1)];
		strcpy_s(label, strlen(s2) + 1, s2);
		selections = n;
		playtime = x;
	}
	Cd::Cd(const Cd &d)
	{
		performers = new char[strlen(d.performers) + 1];
		strcpy_s(performers, strlen(d.performers) + 1, d.performers);
		label = new char[strlen(d.label + 1)];
		strcpy_s(label, strlen(d.label) + 1, d.label);
		selections = d.selections;
		playtime = d.playtime;
	}
	Cd::Cd()
	{
		performers = new char[strlen("default") + 1];
		strcpy_s(performers, strlen("default") + 1, "default");
		label = new char[strlen("default") + 1];
		strcpy_s(label, strlen("default") + 1, "default");
	}
	Cd::~Cd()
	{
		delete[] performers;
		delete[] label;
	}
	void Cd::Report() const
	{
		cout << "Cd performers: " << performers << endl;
		cout << "     Cd label: " << label << endl;
		cout << "Cd selections: " << selections << endl;
		cout << "  Cd playtime: " << playtime << endl;
	}
	Cd & Cd::operator=(const Cd &d)
	{
		if (&d == this)
			return *this;
		delete[] performers;
		delete[] label;
		performers = new char[strlen(d.performers) + 1];
		strcpy_s(performers, strlen(d.performers) + 1, d.performers);
		label = new char[strlen(d.label + 1)];
		strcpy_s(label, strlen(d.label) + 1, d.label);
		selections = d.selections;
		playtime = d.playtime;
		return *this;
	}

	Classic::Classic(char *s1, char *s2, char *s3, int n, double x) :Cd(s2, s3, n, x)
	{
		main = new char[strlen(s1) + 1];
		strcpy_s(main, strlen(s1) + 1, s1);
	}
	Classic::~Classic()
	{
		delete[] main;
	}
	Classic & Classic::operator=(const Classic & c)
	{
		if (&c == this)
			return *this;
		delete[] main;
		Cd::operator=(c);
		main = new char[strlen(c.main) + 1];
		strcpy_s(main, strlen(c.main) + 1, c.main);
		return *this;
	}
	void Classic::Report() const
	{
		Cd::Report();
		cout << " Cd main work: " << main << endl;
	}
	Classic::Classic() :Cd()
	{
		main = new char[strlen("default") + 1];
		strcpy_s(main, strlen("default") + 1, "default");
	}
}

namespace Q3
{
	dmaABC::dmaABC(char *c1, int i) :rating(i)
	{
		label = new char[strlen(c1) + 1];
		strcpy_s(label, strlen(c1) + 1, c1);
	}
	dmaABC::~dmaABC()
	{
		delete[] label;
	}
	void dmaABC::View()
	{
		cout << "DMA label : " << getLabel() << endl;
		cout << "DMA rating: " << getRating() << endl;
	}

	baseDMA::baseDMA(char *c1, int i) :dmaABC(c1,i)
	{}
	void baseDMA::View()
	{
		cout << "Displaying baseDMA object:" << endl;
		dmaABC::View();
		cout << "-------------------" << endl;
	}

	lackDMA::lackDMA(char *c1, int i, char *c2) :dmaABC(c1, i)
	{
		strcpy_s(color, c2);
	}
	void lackDMA::View()
	{
		cout << "Displaying lackDMA object:" << endl;
		dmaABC::View();
		cout << "DMA color : " << color<< endl;
		cout << "-------------------" << endl;
	}

	hasDMA::hasDMA(char *c1, int i, char *c2) :dmaABC(c1, i)
	{
		style = new char[strlen(c2) + 1];
		strcpy_s(style, strlen(c2) + 1, c2);
	}
	hasDMA::~hasDMA()
	{
		delete[] style;
	}
	void hasDMA::View()
	{
		cout << "Displaying hasDMA:" << endl;
		dmaABC::View();
		cout << "DMA style : " << style << endl;
		cout << "-------------------" << endl;
	}
}

namespace Q4
{
	Port::Port(const char *br, const char *st, int b)
	{
		brand = new char[strlen(br) + 1];
		strcpy_s(brand, strlen(br) + 1, br);
		strcpy_s(style, st);
		bottles = b;
	}
	Port::Port(const Port &p)
	{
		brand = new char[strlen(p.brand) + 1];
		strcpy_s(brand, strlen(p.brand) + 1, p.brand);
		strcpy_s(style, p.style);
		bottles = p.bottles;
	}
	Port & Port::operator=(const Port &p)
	{
		if (&p == this)
			return *this;
		delete[] brand;
		brand = new char[strlen(p.brand) + 1];
		strcpy_s(brand, strlen(p.brand) + 1, p.brand);
		strcpy_s(style, p.style);
		bottles = p.bottles;
	}
	Port & Port::operator+=(int b)
	{
		bottles += b;
		return *this;
	}
	Port & Port::operator-=(int b)
	{
		if (b > bottles)
		{
			cout << "Unable to substract, b > bottles!" << endl;
			return *this;
		}
		bottles -= b;
		return *this;
	}
	int Port::BottleCount() const
	{
		return bottles;
	}
	void Port::show() const
	{
		cout << "Brand: " << brand << endl;
		cout << "Kind: " << style << endl; 
		cout << "Bottles:" << bottles << endl;
	}
	ostream & operator<<(ostream &os, const Port &p)
	{
		os << p.brand << ", " << p.style << ", " << p.bottles << endl;
		return os;
	}

	VintagePort::VintagePort() :Port()
	{}
	VintagePort::VintagePort(const char *br, int b, const char *nn, int y) : Port(br, "vintage", b)
	{
		nickname = new char[strlen(nn) + 1];
		strcpy_s(nickname, strlen(nn) + 1, nn);
		year = y;
	}
	VintagePort::VintagePort(const VintagePort &vp) :Port(vp)
	{
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
		year = vp.year;
	}
	VintagePort & VintagePort::operator=(const VintagePort & vp)
	{
		if (&vp == this)
			return *this;
		Port::operator=(vp);
		delete[] nickname;
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
		year = vp.year;
	}
	void VintagePort::show() const
	{
		Port::show();
		cout << "Nickname: " << nickname << endl;
		cout << "Year: " << year << endl;
	}
	ostream & operator<<(ostream &os, VintagePort &vp)
	{
		os << (const Port &)vp;
		os << "Nickname: " << vp.nickname << endl;
		os << "Year: " << vp.year << endl;
		return os;
	}
}