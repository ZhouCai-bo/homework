#include "Declaration.h"

namespace Q1
{
	void process1()
	{
		int ct = 0;
		while (cin.peek() != '#')
		{
			cin.get();
			++ct;
		}
		cout << ct << " charaters./n";
	}
}

namespace Q2
{
	void process2()
	{
		cout << "Enter file name: ";
		string name;
		cin >> name;
		getchar();
		ofstream outf(name.c_str());
		cout << "Enter something, end with a blank line./n";
		string str;
		while (getline(cin, str))
		{
			if (str == "")break;
			outf << str.c_str() << endl;
		}
	}
}

namespace Q3
{
	void process3()
	{
		ifstream inf;
		ofstream outf;
		string infile;
		string outfile;
		cout << "Enter infile name: ";
		cin >> infile;
		inf.open(infile.c_str());
		if (inf.is_open())
		{
			cout << "Enter putfile name: ";
			cin >> outfile;
			outf.open(outfile.c_str());
			if (outf.is_open())
			{
				string temp;
				while (!inf.eof())
				{
					getline(inf, temp);
					outf << temp << endl;
				}
			}
			else
				cerr << "Cannot open outfile!\n";
		}
		else
			cerr << "Cannot open infile!\n";

	}
}

namespace Q4
{
	void process4()
	{
		ifstream inf1("4_in1.txt");
		ifstream inf2("4_in2.txt");
		ofstream outf("4_out.txt");
		string temp1, temp2;
		while (getline(inf1, temp1) || getline(inf2, temp2))
		{
			outf << temp1 + temp2 << endl;
			temp1 = "";
			temp2 = "";
		}
	}
}

namespace Q5
{
	void process5()
	{
		ifstream inf;
		ofstream outf;
		vector<string> st1;
		vector<string> st2;

		cout << "Enter Mat's friends, end with quit:\n";
		string in;
		while (cin >> in && in != "quit")
		{
			st1.push_back(in);
		}
		cout << "Enter Pat's friends, end with quit:\n";
		while (cin >> in && in != "quit")
		{
			st2.push_back(in);
		}

		int ct1 = st1.size();
		int ct2 = st2.size();
		outf.open("5_mat.dat");
		outf.write((char *)&st1, sizeof(vector<string>(st1.size())));
		outf.open("5_pet.dat");
		outf.write((char *)&st2, sizeof(vector<string>(st2.size())));
		outf.close();

		inf.read((char*)&st1, sizeof(vector<string>(ct1)));
		inf.read((char*)&st2, sizeof(vector<string>(ct2)));

		set<string> s1(st1.begin(), st1.end());
		s1.insert(st2.begin(), st2.end());
		vector<string> st3(s1.begin(), s1.end());

		outf.open("5_out.dat");
		outf.write((char *)&st3, sizeof(vector<string>(st3.size())));
		outf.close();
		inf.open("5_out.dat");
		inf.read((char *)&st3, sizeof(vector<string>(st3.size())));
		cout << "After filte, their friends:\n";
		for (auto a : st3)
			cout << a << " ";
		cout << endl;
		
	}
}