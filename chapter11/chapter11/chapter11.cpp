#include"stdafx.h"
#include"declaration.h"

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
	using namespace std;
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
	}
	system("pause");
	return 0;
}

void ansOne()
{
	using namespace VECTOR;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	//ofstream默认为覆盖式写文件，添加ios::app参数便为追加写
	ofstream of("steps.txt", ios::app);
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length : ";
		if (!(cin >> dstep))
		{
			break;
		}
		of << "Target distance: " << target << " Step Size: " << dstep << endl;
		//当当前步长小于目标值时，进入循环
		result.showstep(steps);
		while (result.magval() < target)
		{
			direction = rand() % 360;
			//更新当前步信息,并前进
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			result.showstep(steps);
		}
		of << "After " << steps << " steps, the subject has the following location:\n";
		of << result << endl;
		result.polar_mode();
		of << " or\n" << result << endl;
		of << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";

	}
	cout << "Bye.\n";
}

void ansTwo()
{
	using namespace VECTOR;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length : ";
		if (!(cin >> dstep))
		{
			break;
		}
		//当当前步长小于目标值时，进入循环
		result.showstep(steps);
		while (result.magval() < target)
		{
			direction = rand() % 360;
			//更新当前步信息,并前进
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";

	}
	cout << "Bye.\n";
}

void ansThree()
{
	using namespace Q3;
	using namespace Q3::VECTOR;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	int loop;
	int maxcnt;
	int mincnt;
	double avgcnt = 0.0;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length : ";
		if (!(cin >> dstep))
		{
			break;
		}
		cout << "Enter loop count : ";
		cin >> loop;
		//进入循环
		//新计算一次初始化最大、最小、平均步长
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		maxcnt = steps;
		mincnt = steps;
		avgcnt += steps;

		for (int i = 1; i < loop; i++)
		{
			steps = 0;
			result.reset(0.0, 0.0);
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}
			if (steps < mincnt)
				mincnt = steps;
			if (steps>maxcnt)
				maxcnt = steps;
		}
		avgcnt /= loop;
		break;
	}
	cout << "Max steps = " << maxcnt << endl;
	cout << "Min steps = " << mincnt << endl;
	cout << "Average steps = " << avgcnt << endl;
	cout << "Bye.\n";
}

void ansFour()
{
	
	using namespace Q4;
	Time aida(3, 25);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + Tosca: " << temp << endl;
	temp = 1.17 * aida;
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
}

void ansFive()
//没有写完。。。建议重构
{
	using namespace Q5;
	Stonewt incognito(275,Stonewt::pound);
	Stonewt wolfe(285.7, Stonewt::pound);
	Stonewt taft(21, Stonewt::stones);

	cout << "The celebrity weighed " << incognito ;


}

void ansSix()
{
	
}

void ansSeven()
{
	using namespace Q7;
	complex a(3.0, 4.0);
	complex c;
	cout << "Enter a complex number(q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';
		cout << "a is " << a << endl;
		cout << "a - c is" << a - c << endl; 
		cout << "a + c is" << a + c << endl; 
		cout << "a * c is" << a * c << endl;
		cout << "2 * c is" << 2 * c << endl;
		cout << "Enter a complex number(q to quit):\n";
	}

}

