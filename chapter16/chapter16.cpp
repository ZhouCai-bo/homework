#include"Declaration.h"

void ansOne();
void ansTwo();
void ansThree();
void ansFour();
void ansFive();
void ansSix();
void ansSeven();
void ansEight();
void ansNine();
void ansTen();


int main()
{
	cout << "Question number -->";
	int choice = 0;
	cin >> choice;
	cin.get();
	switch (choice)
	{
	case 1:ansOne(); break;
	case 2:ansTwo(); break;
	case 3:ansThree(); break;
	case 4:ansFour(); break;
	case 5:ansFive(); break;
	case 6:ansSix(); break;
	case 7:ansSeven(); break;
	case 8:ansEight(); break;
	case 9:ansNine(); break;
	case 10:ansTen(); break;
	}
	system("pause");
	return 0;
}

void ansOne()
{
	string in;
	cout << "Enter a string: ";
	cin >> in;
	if (Q1::isPalindrome(in))
		cout << "Right\n";
	else
		cout << "Wrong\n";
}

void ansTwo()
{
	string in;
	cout << "Enter a string: ";
	getline(cin, in);
	if (Q2::isPalindrome(in))
		cout << "Right\n";
	else
		cout << "Wrong\n";
}

void ansThree()
{
	Q3::pocess();
}

void ansFour()
{
	cout.setf(ios_base::fixed);
	cout.precision(2);
	double ar[5]{ 1.0, 3.5, 4.25, 6.9, 1.0 };
	ostream_iterator<double> oit(cout, " ");
	copy(ar, ar + 5, oit);
	cout << endl;
	int edge = Q4::reduce(ar, 5);
	copy(ar, ar + edge, oit);
}

void ansFive()
{
	cout.setf(ios_base::fixed);
	cout.precision(4);
	long ar[5]{ 1, 3, 4, 6, 1 };
	ostream_iterator<long> oit(cout, " ");
	copy(ar, ar + 5, oit);
	cout << endl;
	int edge = Q5::reduce(ar, 5);
	copy(ar, ar + edge, oit);
	cout << endl;

	string st[5]{ "abc", "cde", "bcd", "def", "abc" };
	ostream_iterator<string> oit1(cout, " ");
	copy(st, st + 5, oit1);
	cout << endl;
	int edge1 = Q5::reduce(st, 5);
	copy(st, st + edge1, oit1);
	cout << endl;
}

void ansSix()
{
	using namespace Q6;

	const int MIN_PER_HR = 60;

	srand((unsigned int)time(0));
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	queue<Item> line;

	cout << "Enter the number of simulation hours:";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;
	cout << "Enter the average number of customers per hour: ";
	double prehour;
	cin >> prehour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR;
	Item *temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;
	//单位时间处理
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		//是否有新客户
		if (newcustomer(min_per_cust))
		{
			if (line.size()==qs)
				turnaways++;
			else
			{
				customers++;
				temp = new Item();
				temp->set(cycle);
				line.push(*temp);
			}
		}
		//当前顾客是否服务完毕 && 队列非空
		if (wait_time <= 0 && (line.empty()))
		{
			temp = &line.front();
			line.pop();
			wait_time = temp->ptime();
			line_wait += cycle - temp->when();
			served++;
		}
		if (wait_time > 0)
		{
			wait_time--;
		}
		sum_line += line.size();
	}

	if (customers > 0)
	{
		cout << " customer accepted: " << customers << endl;
		cout << "   customer served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: ";
		cout << (double)line_wait / served << "minutes\n";
	}
	else
	{
		cout << "No customers!\n";
	}
}

void ansSeven()
{
	cout << "Enter number of holes on this ticket: ";
	int nums;
	cin >> nums;
	vector<int> res;
	res = Q7::lottee(nums, 5);
	ostream_iterator<int> iot(cout, "--");
	copy(res.begin(), res.end(), iot);
}

void ansEight()
{
	Q8::process8();
}

void ansNine()
{
	Q9::process9();
}

void ansTen()
{
	using namespace Q10;
	vector<shared_ptr<Review>> books;
	shared_ptr<Review> temp;
	while (FillReview(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "Thank you. Now you check these books by enter" << endl;
		cout << "o(no sort)\na(sort by alphbet)\nra(sort by rating in ascending order)\nrd(sort by rating in descending order)\n";
		cout << "p(sort by price in descending order)\nq(quit)\n";
		int mode;
		while (cin >> mode)
		{
			if (mode == q)
				break;
			switch (mode)
			{
			case o:ShowReview(books); break;
			case a:sortFunc(books, a); ShowReview(books); break;
			case ra:sortFunc(books, ra); ShowReview(books); break;
			case rd:sortFunc(books, ra); ShowReview(books); break;
			case p:sortFunc(books, p); ShowReview(books); break;
			}
				
		}
	}
}