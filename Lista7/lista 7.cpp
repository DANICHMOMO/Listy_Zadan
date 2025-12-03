#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void task2() {
	vector<int> a;
	int x, temp = 0;
	cout << "Input numbers from a to e: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		a.push_back(x);
		if (temp < a.at(i)) {
			temp = a.at(i);
		}
	}
	cout << temp;
}

void task3() {
	vector<int> a;
	int x, min, max;
	cout << "Input numbers from a to e: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	min = max = a.at(1);
	for (int i = 0; i < 5; i++)
	{
		if (max < a.at(i)) {
			max = a.at(i);
		}
		if (min > a.at(i)) {
			min = a.at(i);
		}
	}
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
}

void task4() {
	vector<int> a = {};
	int x;
	cout << "Give numbers of array: ";
	for (int i = 0; i < 4; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < a.size() - 1; i++)
	{
		for (int j = 0; j < a.size() - i - 1; j++)
		{
			if (a[j] < a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
	cout << "Secound Greatest Array: ";
	cout << a.at(1);
}

void task5() {
	vector<int> a = {};
	int x;
	cout << "Give numbers of array: ";
	for (int i = 0; i < 4; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < a.size() - 1; i++)
	{
		for (int j = 0; j < a.size() - i - 1; j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
	cout << "Sorted Array: ";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a.at(i) << ", ";
	}
}

void task6() {
	int d, m, y;
	cout << "Enter day, month and year (e.g. 15 5 2025): ";
	if (!(cin >> d >> m >> y)) {
		cout << "Error: Non-numeric data entered." << endl;
	}
	if (y < 2000 || y > 2099) {
		cout << "Error: Year must be in range 2000-2099." << endl;
	}
	if (m < 1 || m > 12) {
		cout << "Error: Month must be in range 1-12." << endl;
	}
	int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool is_leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
	if (is_leap) {
		days_in_month[2] = 29;
	}
	if (d < 1 || d > days_in_month[m]) {
		cout << "Error: Invalid day. Month " << m
			<< " in year " << y << " has " << days_in_month[m] << " days." << endl;
	}
	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	int yt = y;
	if (m < 3) {
		yt -= 1;
	}
	int result = (yt + yt / 4 - yt / 100 + yt / 400 + t[m - 1] + d) % 7;
	string day_names[] = { "Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday" };
	cout << "The day of the week is: " << day_names[result] << endl;
}

void task7() {
	int a, b, c;
	int delta, x1, x2;
	cin >> a >> b >> c;
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
	{
		cout << "Delta negative";
	}
	if (delta == 0)
	{
		delta = sqrt(delta);
		x1 = (b * (-1)) / (2 * a);
		cout << "Only 1 answer: ";
		cout << x1;
	}
	if (delta > 0)
	{
		delta = sqrt(delta);
		x1 = (b * (-1) - delta) / (2 * a);
		x1 = (b * (-1) + delta) / (2 * a);
		cout << "2 answer: \n";
		cout << "x1: " << x1 << endl;
		cout << "x1: " << x1;
	}
}

void task8() {
	// without cheaks
	// need more knowlage to figure cheaks out
	// for now i commit this and later add nessesery code
	int a11 = 0, a12 = 0, a21 = 0, a22 = 0, b1 = 0, b2 = 0;
	cout << "Enter numbers in this sequence a11, a12, a21, a22, x1, x2: ";
	cin >> a11 >> a12 >> a21 >> a22 >> b1 >> b2;
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