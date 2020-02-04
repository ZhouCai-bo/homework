#ifndef DECLARATION_H_
#define DECLARATION_H_
#include"stdafx.h"
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>

//Q1
namespace VECTOR 
{
	class Vector
	{
	public:
		enum Mode{ RECT, POL };
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double, double, Mode form = RECT);
		void reset(double, double, Mode form = RECT);
		~Vector();
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const{ return mag; }
		double angval()const { return ang; }
		void polar_mode();
		void rect_mode();

		Vector operator+(const Vector&) const;
		Vector operator-(const Vector&) const;
		Vector operator-();
		Vector operator*(double) const;

		friend Vector operator*(double, const Vector&);
		friend std::ostream& operator<<(std::ostream&, const Vector&);

		void showstep(int);
	};
}
//Q2
//代码重复量太大，这里只保留magval（）和angval（）函数
//namespace VECTOR
//{
//public:
//	double magval();
//	double angval();
//}

//Q3
namespace Q3
{
	namespace VECTOR
	{
		class Vector
		{
		public:
			enum Mode{ RECT, POL };
		private:
			double x;
			double y;
			double mag;
			double ang;
			Mode mode;
			void set_mag();
			void set_ang();
			void set_x();
			void set_y();
		public:
			Vector();
			Vector(double, double, Mode form = RECT);
			void reset(double, double, Mode form = RECT);
			~Vector();
			double xval() const { return x; }
			double yval() const { return y; }
			double magval() const{ return mag; }
			double angval()const { return ang; }
			void polar_mode();
			void rect_mode();

			Vector operator+(const Vector&) const;
			Vector operator-(const Vector&) const;
			Vector operator-();
			Vector operator*(double) const;

			friend Vector operator*(double, const Vector&);
			friend std::ostream& operator<<(std::ostream&, const Vector&);
		};
	}
}
//Q4
namespace Q4
{
	class Time
	{
	private:
		int hours;
		int minutes;
	public:
		Time();
		Time(int, int m = 0);
		void AddMin(int);
		void AddHr(int);
		void Reset(int h = 0, int m = 0);
		friend const Time operator+(const Time&, const Time&);
		friend const Time operator-(const Time&, const Time&);
		friend const Time operator*(const Time&, double n);
		friend const Time operator*(double n, Time& t){ return t * n; }
		friend std::ostream& operator<<(std::ostream& os, const Time& t);
	};
}
//Q5
namespace Q5
{
	class Stonewt
	{
	public:
		enum Mode{ stones, pounds, pound };
	private:
		enum{ Lbx_per_stn = 14 };
		double stones_pounds;
		int pd;
		Mode mode = stones;
	public:
		Stonewt();
		Stonewt(double,Mode);
		~Stonewt();
		void setMode(Mode mode = stones);
		Stonewt operator+(Stonewt&) const;
		Stonewt operator-(Stonewt&) const;
		Stonewt operator*(Stonewt&) const;
		friend const std::ostream & operator<<(std::ostream& os, Stonewt);
	};
}
//Q6
//Q7
namespace Q7
{
	class complex
	{
	private:
		double rNum;
		double iNum;
	public:
		complex();
		complex(double, double);
		~complex();
		
		complex operator+(complex) const;
		complex operator-(complex) const;
		complex operator*(complex) const;
		friend const complex operator*(int, complex);
		complex operator~() const;

		//这两个友元函数不能有const关键字，原因未知，可能是返回类型是ostream而不是const ostream
		friend std::ostream& operator<<(std::ostream&, const complex);
		friend std::istream& operator>>(std::istream&, complex&);
	};
}
#endif