#ifndef DECLARATION_H_
#define DECLARATION_H_

#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<cctype>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<array>
#include<valarray>
#include<list>
#include<cstdlib>
#include<ctime>
#include<memory>

using namespace std;

namespace Q1
{
	bool isPalindrome(string &st);
}

namespace Q2
{
	bool isPalindrome(string &st);
}

namespace Q3
{
	void pocess();
}

namespace Q4
{
	int reduce(double ar[], int n);
}

namespace Q5
{
	template<typename T> int reduce(T ar[], int n)
	{
		vector<T> va(ar, ar + n);
		sort(va.begin(), va.end());
		va.erase(unique(va.begin(), va.end()), va.end());
		copy(va.begin(), va.end(), ar);
		return va.size();
	}
}

namespace Q6
{
	bool newcustomer(double x);

	class Customer
	{
	private:
		long arrive;
		int processtime;
	public:
		Customer();
		void set(long when);
		long when() const{ return arrive; }
		int ptime() const{ return processtime; }
	};

	typedef Customer Item;
}

namespace Q7
{
	vector<int> lottee(int nums, int n);
}

namespace Q8
{
	void process8();
}

namespace Q9
{
	void process9();
}

namespace Q10
{
	enum{ o, a, ra, rd, p, q };
	struct Review
	{
		string title;
		int rating;
		int price;
	};
	bool sortAlp(const shared_ptr<Review> ri, const shared_ptr<Review> r2);
	bool sortRaAs(const shared_ptr<Review> ri, const shared_ptr<Review> r2);
	bool sortRaD(const shared_ptr<Review> ri, const shared_ptr<Review> r2);
	bool sortPri(const shared_ptr<Review> ri, const shared_ptr<Review> r2);
	bool FillReview(shared_ptr<Review> rr);
	void ShowReview(const vector<shared_ptr<Review>> rr);

	void sortFunc(vector<shared_ptr<Review>> books, int mode);
}
#endif