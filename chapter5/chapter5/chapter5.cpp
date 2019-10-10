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
	int num1, num2, sum = 0;
	cin >> num1 >> num2;
	for (int i = num1; i <= num2; i++)
	{
		sum += i;
	}
	cout << "Sum= " << sum;
}

void ansTwo()
{
	const int size = 101;
	array<long double, size> factorials;
	factorials[0] = factorials[1] = 1;
	for (int i = 2; i < size; i++)
	{
		factorials[i] = factorials[i - 1] * i;
	}
	for (int i = 0; i < size; i+=5)
	{
		cout << i << "!= " << factorials[i] << endl;
	}
	cout <<  "100!= " << factorials[101] << endl;
}

void ansThree()
{
	cout << "Input number and end with 0." << endl;
	int input = 0, sum = 0;
	cin >> input;
	while (input != 0)
	{
		sum += input;
		cout << "sum= " << sum << endl;
		cin >> input;
	}
}

void ansFour()
{
	float Daphne = 100, Cleo = 100;
	int year = 0;
	while (1)
	{
		Daphne += 100 * 0.1;
		Cleo += Cleo*0.05;
		++year;
		if (Cleo > Daphne)
			break;
	}
	cout << "After " << year << " years ." << endl;
	cout << "Daphne's assets= " << Daphne << endl;
	cout << "Cleo's assets= " << Cleo << endl;
}

void ansFive()
{
	int sell[12], sum = 0;
	char** months = new char*[12]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "Octuber", "November", "December"};
	for (int i = 0; i < 12;i++)
	{
		cout << "Input the sell of " << months[i] << " : ";
		cin >> sell[i];
		sum += sell[i];
	}
	cout << "The total sell of this year is " << sum << "." << endl;
}

void ansSix()
{
	int sell[3][12], sum[3] = { 0 };
	char** months = new char*[12]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "Octuber", "November", "December"};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << "Input the sell of " << months[j] << " at year " << i+1 << " : ";
			cin >> sell[i][j];
			sum[i] += sell[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "The total sell of year " << i << " is " << sum[i] << endl;
	}
}

void ansSeven()
{
	int num=0;
	struct car
	{
		string brand;
		int year;
	};
	cout << "How many cars do you wish to catalog? ";
	cin >> num;
	car* cars = new car[num];
	for (int i = 0; i < num;i++)
	{
		cin.get();
		cout << "Car #" << i+1<<endl;
		cout << "please enter the make: ";
		getline(cin, cars[i].brand);
		cout << "Please enter the year made: ";
		cin >> cars[i].year;
	}
	cout << "Here is your collection:" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << cars[i].year << " " << cars[i].brand << endl;
	}
	
}

void ansEight()
{
	char* word=new char[20];
	int sum = 0;
	cout << "Enter words(to stop, type the word done)" << endl;
	cin >> word;
	while (strcmp(word,"done"))
	{
		++sum;
		cin >> word;
	}
	cout << "You entered a total of " << sum << " words.";
}

void ansNine()
{
	string word;
	int sum = 0;
	cout << "Enter words(to stop, type the word done)" << endl;
	cin >> word;
	while (word!="done")
	{
		++sum;
		cin >> word;
	}
	cout << "You entered a total of " << sum << " words.";
}

void ansTen()
{
	int rows = 0;
	cout << "Enter numbers of rows: ";
	cin >> rows;
	for (int i = 0; i < rows; i++)
	{
		for (int m = 1; m < rows - i; m++)
		{
			cout << ".";
		}
		for (int n = 0; n <= i;n++)
		{
			cout << "*";
		}
		cout << endl;
	}
}