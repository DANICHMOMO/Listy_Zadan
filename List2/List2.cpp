#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int task1() {
	int x;
	cout << "Enter x: ";
	cin >> x;
	double output = pow(x, 5);
	cout << "Answer to Task 1 is: " << output;
	return 0;
}

int task2() {
	int a, b, c;
	int S, V;
	cout << "Enter a, b, c: ";
	cin >> a >> b >> c;
	V = a * b * c;
	S = 2 * (a * b + a * c + b * c);
	cout << "Volume of the figure is: " << V << "\n";
	cout << "Surface area of the figure is: " << S << "\n";
	return 0;
}

int task3() {
	int x;
	cout << "Enter x: ";
	cin >> x;
	double output = pow(x, 10);
	cout << "Answer to Task 7 is: " << output;
	return 0;
}

int task4() {
	int n = 6;
	double x;
	cout << "Enter value of x: ";
	cin >> x;
	vector<double> coefficients(n + 1);
	cout << "Enter coefficients starting from a_n down to a_0:" << endl;
	for (int i = 0; i <= n; i++) {
		cout << "a_" << (n - i) << ": ";
		cin >> coefficients[i];
	}
	double result = coefficients[0];
	for (int i = 1; i <= n; i++) {
		result = result * x + coefficients[i];
	}
	cout << "Result W(" << x << ") = " << result << endl;
}

int task5() {
	int x;
	cout << "Enter x: ";
	cin >> x;
		if (x % 2 == 0)
		{
			cout << "0";
		}
		else
		{
			cout << "1";
		}
	return 0;
}

int task6() {
	int x = 0;
	int y = 1;
	int buffer = 0;
	cout << x << "\n";
	cout << y << "\n";
	for (int i = 0; i < 8; i++)	
	{
		buffer = y + x;
		x = y;
		y = buffer;
		cout << buffer << "\n";
	}
	
	return 0;
}

int task7() {
	int x;
	cout << "Enter x: ";
	cin >> x;
	if (x % 3 == 0)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
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
	}
	return 0;
}