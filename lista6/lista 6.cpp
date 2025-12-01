#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void task1() {
	double h, a;
	cout << "Give Height and side of piramide: ";
	cin >> h >> a;
	double sidesArea = 3 * a * h;
	double bottomArea = (3 * a * a * sqrt(3)) / 2;
	double output = sidesArea + bottomArea;
	cout << output;
}

void task2() {
	//int a10 = 0, a9 = 0, a8 = 0, a7 = 0, a6 = 0, a5 = 0, a4 = 0, a3 = 0, a2 = 0, a1 = 0, a0 = 0;
	vector<int> a;
	int x, output = 0;
	cout << "Enter 11 coefficients, starting with a10 down to a0:\n";
	cout << "(e.g., a10 a9 a8 a7 a6 a5 a4 a3 a2 a1 a)\n";
	//cin >> a10 >> a9 >> a8 >> a7 >> a6 >> a5 >> a4 >> a3 >> a2 >> a1 >> a0;
	for (int i = 0; i < 11; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	cout << "Enter x: ";
	cin >> x;
	for (int i = 0; i < 11; ++i)
	{
		output = output * x + a[i];
	}
	//output = a10 * pow(x, 10) + a9 * pow(x, 9) + a8 * pow(x, 8) + a7 * pow(x, 7) + a6 * pow(x, 6) + a5 * pow(x, 5) + a4 * pow(x, 4) + a3 * pow(x, 3) + a2 * pow(x, 2) + a1 * x + a0;

	cout << "Answer to Task 5 is: " << output << "\n";
}

void task3() {
	int a, b;
	long long output;
	cout << "Give A: ";
	cin >> a;
	cout << "Give B: ";
	cin >> b;
	if (a > 0)
	{	
		output = pow(a, b);
	}
	cout << output;
}

void task4() {
	int n, x;
	double output = 0;
	vector<int> a /*= { 42, 7, 19, 88, 3, 56, 21, 90, 12, 34, 67, 5, 29, 73, 15, 8, 99, 45, 62, 11, 23, 81, 37, 4, 50, 76, 9, 31, 64, 2 }*/;
	// comment array if you want to enter your numbers
	if (a.size() == 0) {
		cout << "Enter amount of elements in array: ";
		cin >> n;
		cout << "Give numbers of array: ";
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			a.push_back(x);
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		output = output + a.at(i);
	}
	output = output / a.size();
	cout << "Arythmetical mean: " << output << "\n";
	output = 0;
	for (int i = 0; i < a.size(); i++)
	{
		output = (output + (1.0 / a.at(i)));
	}
	output = a.size() / output ;
	cout << "Harmonic mean: " << output;
}

void task5() {
	int x;
	double output;
	cout << "Enter x: ";
	cin >> x;
	output = pow(x, 59);
	cout << "Answer to Task 5 is: " << output;
}

void task6() {
	int x = 1;
	int y = 1;
	int buffer = 0;
	cout << "A1: " << x << "\n";
	cout << "A2: " << y << "\n";
	for (int i = 0; i < 10; i++)
	{
		buffer = y + x;
		x = y;
		y = buffer;
		cout << buffer << "\n";
	}
}

void task7() {
	int x;
	int output[3] = { 1, 0, 0 };
	cout << "Enter x: ";
	cin >> x;
	cout << output[x % 3];
}

void task8() {
	int a11 = 0, a12 = 0, a21 = 0, a22 = 0, b1 = 0, b2 = 0;
	cout << "Enter numbers in this sequence a11, a12, a21, a22, x1, x2: ";
	cin >> a11>> a12 >> a21 >> a22 >> b1 >> b2;
	int D = a11 * a22 - a12 * a21;
	int x1 = (b1 * a22 - a12 * b2) / D;
	int x2 = (a11 * b2 - b1 * a21) / D;
	cout << "X1: " << b1 << "\n" << "X2: " << b2 << "\n";
}

int main() {
	int x;
	cout << "Chouse homework Task from first List by correspondin number: ";
	cin >> x;
	switch (x) {
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	case 4:
		task4();
		break;
	case 5:
		task5();
		break;
	case 6:
		task6();
		break;
	case 7:
		task7();
		break;
	case 8:
		task8();
		break;
	}
	return 0;
}