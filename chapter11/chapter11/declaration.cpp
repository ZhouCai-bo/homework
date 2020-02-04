#include "stdafx.h"
#include "declaration.h"

using namespace std;

//Q1
namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);
	
	void Vector::set_mag()
	{
		mag = sqrt(x*x + y*y);
	}
	void Vector::set_ang()
	{
		if (x == 0.0&&y == 0.0)
		{
			ang = 0.0;
		}
		else
		{
			ang = atan2(y, x);
		}
	}
	void Vector::set_x()
	{
		x = mag*cos(ang);
	}
	void Vector::set_y()
	{
		y = mag*sin(ang);
	}

	Vector::Vector()
	{
		x = y = mag = ang = 0;
	}
	Vector::Vector(double n1, double n2, Mode form )
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() --";
			cout << "Vector set to 0\n";
			x = y = ang = mag = 0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() --";
			cout << "Vector set to 0\n";
			x = y = ang = mag = 0;
			mode = RECT;
		}
	}
	Vector::~Vector(){}
	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-()
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const
	{
		return Vector(x*n, y*n);
	}

	Vector operator*(double n, const Vector& a)
	{
		return a*n;
	}
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
		{
			os << "(x,y) = ( " << v.x << " , " << v.y << " )";
		}
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = ( " << v.mag << " , " << v.ang << " )";
		}
		else
		{
			os << "Vector object mode is valid!";
		}
		return os;
	}
	void Vector::showstep(int n)
	{
		ofstream of("steps.txt",ios::app);
		of << n << " : (x , y) = ( " << xval() << " , " << yval() << " )" << endl;
	}
}
//Q2
//代码重复量太大，这里只保留magval（）和angval（）函数
/*namespace VECTOR
{
public:
	double magval()
	{
		return mag = sqrt(x*x + y*y);
	}
	double angval()
	{
		if (x == 0.0&&y == 0.0)
		{
			return 0.0;
		}
		else
		{
			return atan2(y, x);
		}
	}
}*/
//Q3
namespace Q3
{
	namespace VECTOR
	{
		const double Rad_to_deg = 45.0 / atan(1.0);

		void Vector::set_mag()
		{
			mag = sqrt(x*x + y*y);
		}
		void Vector::set_ang()
		{
			if (x == 0.0&&y == 0.0)
			{
				ang = 0.0;
			}
			else
			{
				ang = atan2(y, x);
			}
		}
		void Vector::set_x()
		{
			x = mag*cos(ang);
		}
		void Vector::set_y()
		{
			y = mag*sin(ang);
		}

		Vector::Vector()
		{
			x = y = mag = ang = 0;
		}
		Vector::Vector(double n1, double n2, Mode form)
		{
			mode = form;
			if (form == RECT)
			{
				x = n1;
				y = n2;
				set_ang();
				set_mag();
			}
			else if (form == POL)
			{
				mag = n1;
				ang = n2;
				set_x();
				set_y();
			}
			else
			{
				cout << "Incorrect 3rd argument to Vector() --";
				cout << "Vector set to 0\n";
				x = y = ang = mag = 0;
				mode = RECT;
			}
		}
		void Vector::reset(double n1, double n2, Mode form)
		{
			mode = form;
			if (form == RECT)
			{
				x = n1;
				y = n2;
				set_ang();
				set_mag();
			}
			else if (form == POL)
			{
				mag = n1;
				ang = n2;
				set_x();
				set_y();
			}
			else
			{
				cout << "Incorrect 3rd argument to Vector() --";
				cout << "Vector set to 0\n";
				x = y = ang = mag = 0;
				mode = RECT;
			}
		}
		Vector::~Vector(){}
		void Vector::polar_mode()
		{
			mode = POL;
		}
		void Vector::rect_mode()
		{
			mode = RECT;
		}

		Vector Vector::operator+(const Vector& b) const
		{
			return Vector(x + b.x, y + b.y);
		}
		Vector Vector::operator-(const Vector& b) const
		{
			return Vector(x - b.x, y - b.y);
		}
		Vector Vector::operator-()
		{
			return Vector(-x, -y);
		}
		Vector Vector::operator*(double n) const
		{
			return Vector(x*n, y*n);
		}

		Vector operator*(double n, const Vector& a)
		{
			return a*n;
		}
		std::ostream& operator<<(std::ostream& os, const Vector& v)
		{
			if (v.mode == Vector::RECT)
			{
				os << "(x,y) = ( " << v.x << " , " << v.y << " )";
			}
			else if (v.mode == Vector::POL)
			{
				os << "(m,a) = ( " << v.mag << " , " << v.ang << " )";
			}
			else
			{
				os << "Vector object mode is valid!";
			}
			return os;
		}
	}
}
//Q4
namespace Q4
{
	Time::Time()
	{
		hours = minutes = 0;
	}
	Time::Time(int h, int m)
	{
		hours = h;
		minutes = m;
	}
	void Time::AddMin(int n)
	{
		minutes += n;
		hours += minutes / 60;
		minutes %= 60;
	}
	void Time::AddHr(int n)
	{
		hours += n;
	}
	void Time::Reset(int h, int m)
	{
		hours = h;
		minutes = m;
	}
	const Time operator+(const Time& t1, const Time& t2)
	{
		return Time(t1.hours + t2.hours, t1.minutes + t2.minutes);
	}
	const Time operator-(const Time& t1, const Time& t2)
	{
		return Time(t1.hours - t2.hours, t1.minutes - t2.minutes);
	}
	const Time operator*(const Time& t, double n)
	{
		return Time(t.hours*n + (t.minutes*n) / 60, int(t.minutes * n) % 60);
	}
	std::ostream& operator<<(std::ostream& os, const Time& t)
	{
		os << t.hours << " hours, " << t.minutes << " minutes";
		return os;
	}
}
//Q5
namespace Q5
{
	Stonewt::Stonewt()
	{
		stones_pounds = 0.0;
		pd = 0;
	}
	Stonewt::Stonewt(double p,Mode m = stones)
	{
		mode = m;
		if (mode == stones)
			stones_pounds = p;
		
		else if (mode == pound)
			pd = int(p);
		else if (mode == pounds)
			stones_pounds = p;
	}
	Stonewt::~Stonewt(){}
	void Stonewt::setMode(Mode m)
	{
		mode = m;
		if (m == mode)
			return;
		if (mode == stones&&m == pound)
			pd = int(stones / Lbx_per_stn);
		else if (mode == pounds&&m == pound)
			pd = int(stones_pounds);
		else if (mode == stones&&m == pounds)
			stones_pounds = stones / Lbx_per_stn;
		else if (mode == pound&&m == pounds)
		{
		}
		else if ((mode == pound || mode == pounds) && m == stones)
			stones_pounds *= Lbx_per_stn;
	}
	Stonewt Stonewt::operator+(Stonewt& s) const
	{
		if (mode != s.mode)
		{
			s.setMode(mode);
		}
		if (mode == pound)
			return Stonewt(pd + s.pd);
		else if (mode == pounds)
			return Stonewt(stones_pounds + s.stones_pounds, pounds);
		else
			return Stonewt(stones_pounds + s.stones_pounds, stones);
	}
	Stonewt Stonewt::operator-(Stonewt& s) const
	{
		if (mode != s.mode)
		{
			s.setMode(mode);
		}
		if (mode == pound)
			return Stonewt(pd - s.pd);
		else if (mode == pounds)
			return Stonewt(stones_pounds - s.stones_pounds, pounds);
		else
			return Stonewt(stones_pounds - s.stones_pounds, stones);
	}
	Stonewt Stonewt::operator*(Stonewt& s) const
	{
		if (mode != s.mode)
		{
			s.setMode(mode);
		}
		if (mode == pound)
			return Stonewt(pd * s.pd);
		else if (mode == pounds)
			return Stonewt(stones_pounds * s.stones_pounds, pounds);
		else
			return Stonewt(stones_pounds * s.stones_pounds, stones);
	}
	const std::ostream & operator<<(std::ostream& os, Stonewt s)
	{
		if (s.mode == s.pound)
			os << "Pounds: " << s.stones_pounds << endl;
		else if (s.mode == s.pounds)
			os << "Pound: " << s.pd << endl;
		else
			os << "Stones: " << s.stones_pounds << endl;
		return os;
	}
}
//Q6
//Q7
namespace Q7
{
	complex::complex()
	{
		rNum = 0.0;
		iNum = 0.0;
	}
	complex::complex(double r, double i)
	{
		rNum = r;
		iNum = i;
	}
	complex::~complex()
	{}

	complex complex::operator+(complex c) const
	{
		return complex(c.rNum + rNum, c.iNum + iNum);
	}
	complex complex::operator-(complex c) const
	{
		return complex(c.rNum - rNum, c.iNum - iNum);
	}
	complex complex::operator*(complex c) const
	{
		return complex(rNum*c.rNum - iNum*c.iNum, rNum*c.iNum + iNum*c.rNum);
	}
	const complex operator*(int i, complex c)
	{
		return complex(i*c.rNum, i*c.iNum);
	}
	complex complex::operator~() const
	{
		return complex(rNum, -iNum);
	}

	std::ostream& operator<<(std::ostream& os, const complex c)
	{
		os << "( " << c.rNum << " , " << c.iNum << " )" << endl;
		return os;
	}
	std::istream& operator>>(std::istream& is, complex &c)
	{
		is >> c.rNum >> c.iNum;
		return is;
	}
}