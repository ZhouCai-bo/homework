#include<iostream>
#include<cstring>
#include<string>
#include<array>

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
	cout <<  "Question number -->";
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
	getchar();
	getchar();
	return 0;
}

void ansOne()
{
	char fname[20]="", lname[20]="", grade;
	int age;
	cout << "What is your first name? " ;
	cin.getline(fname,20);
	cout << "What is your lname name? " ;
	cin.getline(lname, 20);
	cout << "What letter gradde do you deserve? " ;
	cin >> grade;
	cout << "What is your age ? " ;
	cin >> age;
	grade++;
	cout << "Name: " << lname << "," << fname << endl;
	cout << "Grade: " << (char)grade << endl;;
	cout << "Age: " << age;
}

void ansTwo()
{
	string fname, lname;
	char grade;
	int age;
	cout << "What is your first name? ";
	getline(cin,fname);
	cout << "What is your last name? ";
	getline(cin, lname);
	cout << "What letter grade do you deserve? ";
	cin >> grade;
	cout << "What is your age ? ";
	cin >> age;
	grade++;
	cout << "Name: " << lname << "," << fname << endl;
	cout << "Grade: " << (char)grade << endl;;
	cout << "Age: " << age;
}

void ansThree()
{
	char *fname=new char[] ;
	char *lname=new char[] ;
	char *wholename=new char[] ;
	cout << "Enter your first name: ";
	cin >> fname;
	cout << "Enter your last name: ";
	cin >> lname;
	strcpy(wholename,lname);
	strcat(wholename, ",");
	strcat(wholename, fname);
	cout << "Here's the information in a single string: " << wholename << endl;
	/*
	delete fname;
	delete lname;
	delete wholename;
	*/
}

void ansFour()
{
	string fname;
	string lname;
	string wholename;
	cout << "Enter your first name: ";
	cin >> fname;
	cout << "Enter your last name: ";
	cin >> lname;
	wholename = lname + "," + fname;
	cout << "Here's the information in a single string: " << wholename << endl;
}

void ansFive()
{
	struct CandyBar
	{
		string brand;
		float weight;
		int calorie;
	}snack{ "Mocha Munch", 2.3, 350 };
	cout << "Brand: " << snack.brand << endl;
	cout << "Weight: " << snack.weight << endl;
	cout << "Calorie: " << snack.calorie << endl;
}

void ansSix()
{
	struct CandyBar
	{
		string brand;
		float weight;
		int calorie;
	};
	CandyBar cbs[3] = { { "Mocha Bar", 2.3, 350 }, { "Big Rabbit", 1.6, 200 }, { "Xufu's", 2.1, 300 } };
	for (int i = 0; i < 3; i++)
	{
		cout << "Brand: " << cbs[i].brand << endl;
		cout << "Weight: " << cbs[i].weight << endl;
		cout << "Calorie: " << cbs[i].calorie << endl<<endl;
	}
}

void ansSeven()
{
	struct pizza
	{
		string name;
		int diameter;
		int weight;
	}piz;
	cout << "Input pizza name-->";
	getline(cin, piz.name);
	cout << "Input pizza diameter-->";
	cin >> piz.diameter;
	cout << "Input pizza weight-->";
	cin >> piz.weight;
	cout << "Your pizza's name:" << piz.name << endl;
	cout << "Your pizza's diameter:" << piz.diameter << endl;
	cout << "Your pizza's weight:" << piz.weight << endl;
}

void ansEight()
{
	struct pizza
	{
		string name;
		int diameter;
		int weight;
	};
	pizza* piz = new pizza{};
	cout << "Input pizza diameter-->";
	cin >> piz->diameter;
	cin.get();
	cout << "Input pizza name-->";
	getline(cin, piz->name);
	cout << "Input pizza weight-->";
	cin >> piz->weight;
	cout << "Your pizza's name:" << piz->name << endl;
	cout << "Your pizza's diameter:" << piz->diameter << endl;
	cout << "Your pizza's weight:" << piz->weight << endl;
}

void ansNine()
{
	struct CandyBar
	{
		string brand;
		float weight;
		int calorie;
	};
	CandyBar* cbs = new CandyBar[3];
	cbs[0].brand = "Mocha Bar";
	cbs[0].weight = 2.3;
	cbs[0].calorie = 350;
	cbs[1].brand = "Big Rabbit";
	cbs[1].weight = 1.6;
	cbs[1].calorie = 200;
	cbs[2].brand = "Xufu's";
	cbs[2].weight = 2.1;
	cbs[2].calorie = 300;
	for (int i = 0; i < 3; i++)
	{
		cout << "Brand: " << cbs[i].brand << endl;
		cout << "Weight: " << cbs[i].weight << endl;
		cout << "Calorie: " << cbs[i].calorie << endl << endl;
	}
	//cout << sizeof(*cbs) << "  " << sizeof(cbs[1]);
}

void ansTen()
{
	array<int, 3> score;
	float avg = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "Input score No." << i + 1 << " -->";
		cin >> score[i];
		avg += score[i];
	}
	cout << "Times: " << 3 << endl;
	cout << "Average score: " <<avg/3 << endl;
}