#include<iostream>
#include<cstring>
#include<string>
#include<array>
#include<vector>
#include<cctype>
#include<fstream>

using namespace std;

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
	char ch;
	int i = 0;
	char words[50];
	for (int i = 0; i<50; i++)
	{
		words[i] = '\0';
	}
	while (cin.get(ch)&&ch != '@')
	{
		if (isdigit(ch))
		{
			//do nothing
		}
		else if (islower(ch))
		{
			words[i++] = toupper(ch);
		}
		else if (isupper(ch))
		{
			words[i++] = tolower(ch);
		}
		else
		{
			words[i++] = ch;
		}
	}
	cout << words << endl;
}

void ansTwo()
{
	vector<double> donation(10);
	bool tag = true;
	//array<double,10> donation;
	double sum = 0, avg = 0;
	string line;
	int bigNum = 0, index = 0;
	getline(cin,line);
	while (index<=9&&tag)
	{
		for (int i = 0; i < line.size(); i++)
		{
			if (isdigit(line[i]) || ispunct(line[i]))
			{
				continue;
			}
			else
				tag = false;
		}
		if (tag)
		{
			donation[index++] = stod(line);
			sum += stod(line);
			getline(cin, line);
		}
			
	}
	index;
	avg = sum / index;
	for (int i = 0; i<index; i++)
	{
		if (donation[i] > avg)
		{
			++bigNum;
		}
	}
	cout << "The average number is " << avg << endl;
	cout <<bigNum<< " Bigger than the average number. " << endl;
}

void ansThree()
{
	char input;
	string choice;
	cout << "Please enter a c,p,t or g :";
	cin >> input;
	while (input != 'c'&&input != 'p'&&input != 't'&&input != 'g')
	{
		cout << "Please enter a c,p,t or g :";
		cin >> input;
	}
	switch (input)
	{
	case 'c':choice = "carnivore"; break;
	case 'p':choice = "pianist"; break;
	case 't':choice = "tree"; break;
	case 'g':choice = "game";
	}
	cout << "A maple is a " << choice << endl;
}

void ansFour()
{
	const int strsize = 20;
	char input;
	struct bop
	{
		char fullname[strsize];
		char title[strsize];
		char bopname[strsize];
		int preference;
	};
	bop members[5] = { { "Wimp Macho", "CEO", "Jerk", 0 }, { "Raki Rhodes", "Programmer", "Baster", 1 }, { "Celia Laiter", "High Manager", "Asshole", 2 },
	{ "Hoppy Hipman", "CPO", "phymaid", 0 }, { "Pet Hand", "Cleaner", "Messey", 1 } };
	cout << "Benevolent Order of Programmers Report" << endl;
	cout << "a.display by name\tb.display by title" << endl;
	cout << "c.display by bopname\td.display by preference" << endl;
	cout << "q.quit" << endl;
	cin >> input;
	while (input != 'q')
	{
		switch (input)
		{
		case'a':for (bop b : members){ cout << b.fullname << endl; }; break;
		case'b':for (bop b : members){ cout << b.title << endl; }; break;
		case'c':for (bop b : members){ cout << b.bopname << endl; }; break;
		case'd':
			for (bop b : members)
			{
				if (b.preference == 0)
				{
					cout << b.fullname << endl;
				}
				else if (b.preference == 1)
				{
					cout << b.title << endl;
				}
				else if (b.preference == 2)
				{
					cout << b.bopname << endl;
				}
			};
			break;
		}
		cin >> input;
	}
}

void ansFive()
{
	int tvarps, sum = 0, lel = 0;
	cin >> tvarps;
	if (tvarps > 5000 && tvarps <= 15000)
	{
		lel = 1;
	}
	else if (tvarps > 15000 && tvarps <= 35000)
	{
		lel = 2;
	}
	else if (tvarps > 35000)
	{
		lel = 3;
	}
	switch (lel)
	{
	case 3:sum = (tvarps - 35000)*0.2 + 20000 * 0.15 + 10000 * 0.1 + 5000 * 0.0; break;
	case 2:sum = (tvarps - 15000) * 0.15 + 10000 * 0.1 + 5000 * 0.0; break;
	case 1:sum = (tvarps - 5000) * 0.1 + 5000 * 0.0; break;
	case 0:sum = 0; break;
	} 
	cout << "Tax= " << sum << endl;
}

void ansSix()
{
	struct donater
	{
		string name;
		int donation;
	};
	int cnt = 0;
	cin >> cnt;
	cin.get();
	donater* ds = new donater[cnt];
	string dname;
	for (int i = 0; i < cnt;i++)
	{
		getline(cin,ds[i].name);
		cin >> ds[i].donation;
		cin.get();
	}
	cout << "Grand Patrons:" << endl;
	for (int i = 0; i < cnt; i++)
	{
		if (ds[i].donation>10000)
		{
			cout << ds[i].name << endl;
		}
	}
	cout << "Patrons:" << endl;
	for (int i = 0; i < cnt; i++)
	{
		if (ds[i].donation<=10000)
		{
			cout << ds[i].name << endl;
		}
	}
}

void ansSeven()
{
	cout << "Enter words (q to quit)" << endl;
	char word[10];
	int vowels = 0, consonants = 0, other = 0;
	cin >> word;
	while (strcmp(word,"q"))
	{
		if (isalpha(word[0]))
		{
			if (word[0] == 'a' || word[0] == 'o' || word[0] == 'i' || word[0] == 'e' || word[0] == 'u')
			{
				++vowels;
			}
			else
			{
				++consonants;
			}
		}
		else
			++other;
		cin >> word;
	}
	cout << vowels << " words begining with vowels" << endl;
	cout << consonants << " words begining with consonants" << endl;
	cout << other << " others" << endl;
}

void ansEight()
{
	ifstream infile;
	infile.open("inFile.txt");
	char ch;
	int sum = 0;
	while (infile.get(ch))
	{
		++sum;
	}
	cout << sum << " chars read." << endl;
}

void ansNine()
{
	struct donater
	{
		string name;
		int donation;
	};
	ifstream infile;
	infile.open("inFile.txt");
	int cnt = 0;
	infile >> cnt;
	infile.get();
	donater* ds = new donater[cnt];
	string dname;
	for (int i = 0; i < cnt; i++)
	{
		getline(infile, ds[i].name);
		infile >> ds[i].donation;
		infile.get();
	}
	cout << "Grand Patrons:" << endl;
	for (int i = 0; i < cnt; i++)
	{
		if (ds[i].donation>10000)
		{
			cout << ds[i].name << endl;
		}
	}
	cout << "Patrons:" << endl;
	for (int i = 0; i < cnt; i++)
	{
		if (ds[i].donation <= 10000)
		{
			cout << ds[i].name << endl;
		}
	}
}

void ansTen(){}