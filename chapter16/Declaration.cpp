#include "Declaration.h"

namespace Q1
{
	bool isPalindrome(string &st)
	{
		transform(st.begin(), st.end(), st.begin(), tolower);
		cout << st;
		auto front = st.begin();
		auto back = st.end() - 1;
		while (front < back)
		{
			if (*front++ != *back--)
				return false;
		}
		return true;
	}
}

namespace Q2
{
	bool isPalindrome(string &st)
	{
		for (auto itr = st.begin(); itr != st.end(); itr++)
		{
			if (ispunct(*itr) || isspace(*itr))   //erase删除元素后，会将剩余元素迁移，迭代器再次后移会导致部分元素未判断
				st.erase(itr--);
		}
		return Q1::isPalindrome(st);
	}
}

namespace Q3
{
	void pocess()
	{
		vector<string> s1;
		vector<string> s2;
		string temp;

		ifstream iFile;
		iFile.open("test1.txt");
		while (!iFile.eof())
		{
			iFile >> temp;
			s1.push_back(temp);
		}
		iFile.close();
		iFile.open("test2.txt");
		while (!iFile.eof())
		{
			iFile >> temp;
			s2.push_back(temp);
		}
		iFile.close();

		set<string> A(s1.begin(), s1.end());
		set<string> B(s2.begin(), s2.end());

		ostream_iterator<string, char> out(cout, " ");
		cout << "Set A: ";
		copy(A.begin(), A.end(), out);
		cout << endl;
		cout << "Set B: ";
		copy(B.begin(), B.end(), out);
		cout << endl;
		cout << "Union of A and B:\n ";
		set_union(A.begin(), A.end(), B.begin(), B.end(), out);
		cout << endl;

		cout << "Intersection of A and B:\n ";
		set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
		cout << endl;

		cout << "Different of A and B:\n";
		set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
		cout << endl;

		set<string> C;
		cout << "Set C:\n";
		set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
		copy(C.begin(), C.end(), out);
		cout << endl;

		string s3("grungy");
		C.insert(s3);
		cout << "Set C after insertion:\n";
		copy(C.begin(), C.end(), out);
		cout << endl;

		cout << "Showing a range:\n";
		copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
		cout << endl;
	}
}

namespace Q4
{
	int reduce(double ar[], int n)
	{
		vector<double> va(ar, ar + n);
		sort(va.begin(), va.end());
		va.erase(unique(va.begin(), va.end()), va.end());
		copy(va.begin(), va.end(), ar);
		return va.size();
	}
}

namespace Q5
{
}

namespace Q6
{
	bool newcustomer(double x)
	{
		return (rand()*x / RAND_MAX < 1);
	}

	void Customer::set(long when)
	{
		processtime = rand() % 3 + 1;
		arrive = when;
	}

	Customer::Customer()
	{
	}
}

namespace Q7
{
	vector<int> lottee(int nums, int n)
	{
		vector<int> rd(nums);
		vector<int> res(n);
		for (int i = 0; i < rd.size(); i++)
			rd[i] = i + 1;
		random_shuffle(rd.begin(), rd.end());
		copy(rd.begin(), rd.begin() + n, res.begin());
		return res;
	}
}

namespace Q8
{
	void process8()
	{
		vector<string> st1;
		vector<string> st2;
		cout << "Enter Mat's friends, end with quit:\n";
		string in;
		while (cin>>in && in != "quit")
		{
			st1.push_back(in);
		}
		cout << "Enter Pat's friends, end with quit:\n";
		while (cin >> in && in != "quit")
		{
			st2.push_back(in);
		}

		sort(st1.begin(), st1.end());
		sort(st2.begin(), st2.end());
		ostream_iterator<string> iot(cout, " ");
		cout << "Mat's friends:\n";
		copy(st1.begin(), st1.end(), iot);
		cout << endl;
		cout << "Pat's friends:\n";
		copy(st2.begin(), st2.end(), iot);
		cout << endl;

		cout << "After filte, their friends:\n";
		set<string> s1(st1.begin(), st1.end());
		set<string> s2(st2.begin(), st2.end());
		set_union(s1.begin(), s1.end(),s2.begin(),s2.end(), iot);
	}
}

namespace Q9
{
	void process9()
	{
		vector<int> vi0(50000);
		vector<int> vi(50000);
		list<int> li(50000);

		for (int i = 0; i < vi0.size(); i++)
		{
			srand(i);
			vi0[i] = rand();
		}

		vi = vi0;
		copy(vi0.begin(), vi0.end(), li.begin());

		clock_t start = clock();
		sort(vi.begin(), vi.end());
		clock_t end = clock();
		cout << "Time for sort vector: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
		start = clock();
		li.sort();
		end = clock();
		cout << "Time for sort list: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

		start = clock();
		copy(vi0.begin(), vi0.end(), li.begin());
		copy(li.begin(), li.end(), vi.begin());
		sort(vi.begin(), vi.end());
		end = clock();
		cout << "Time for sort after copy list to vector: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	}

}

namespace Q10
{
	bool sortAlp(const shared_ptr<Review> ri, const shared_ptr<Review> r2)
	{
		if (ri->title < r2->title)
			return true;
		else if (ri->title == r2->title && ri->rating < r2->rating)
			return true;
		else
			return false;
	}
	bool sortRaAs(const shared_ptr<Review> ri, const shared_ptr<Review> r2)
	{
		if (ri->rating <= r2->rating)
			return true;
		else
			return false;
	}
	bool sortRaD(const shared_ptr<Review> ri, const shared_ptr<Review> r2)
	{
		if (ri->rating >= r2->rating)
			return true;
		else
			return false;

	}
	bool sortPri(const shared_ptr<Review> ri, const shared_ptr<Review> r2)
	{
		if (ri->price >= r2->price)
			return true;
		else
			return false;
	}
	bool FillReview(shared_ptr<Review> rr)
	{
		shared_ptr<Review> t (new Review);
		cout << "Enter book title: ";
		getline(cin, t->title);
		cout << "Enter book rating: ";
		cin >> t->rating;
		cout << "Enter book price: ";
		cin >> t->price;
		rr = t;
		return true;

	}
	void ShowReview(const vector<shared_ptr<Review>> rr)
	{
		for (auto a:rr)
			cout << a->rating << "\t" << a->title << "\t" << a->price << endl;
	}
	void sortFunc(vector<shared_ptr<Review>> books, int mode)
	{
		switch (mode)
		{
		case a:sort(books.begin(), books.end(), sortAlp); break;
		case ra:sort(books.begin(), books.end(), sortRaAs); break;
		case rd:sort(books.begin(), books.end(), sortRaD); break;
		case p:sort(books.begin(), books.end(), sortPri); break;
		}
			
	}
}