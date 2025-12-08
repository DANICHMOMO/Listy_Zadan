#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void task1() {
	
}

void task2() {
	vector<int> a;
	int x;
	cout << "Enter numbers:" << endl;
	while (cin >> x) {
		if (x == 0) break;
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
	cout << "Third Greatest Array: ";
	cout << a.at(2);
}

void task3() {

}

void task4() {

}

void task5() {
	vector<int> a;
	int count = 0, n, x;
	cout << "Enter numbers:" << endl;
	while (cin >> x) {
		if (x == 0) break;
		a.push_back(x);
	}
	for (int i = 0; i < a.size() - 2; i++)
	{
		if ((a[i] * a[i]) + (a[i + 1] * a[i + 1]) == a[i + 2])
		{
			count++;
		}
	}
	cout << count;
}

void task6() {

}

void task7() {
	unsigned long long a, b; 
	cout << "Give number a (start of range): ";
	cin >> a;
	cout << "Give number b (end of range): ";
	cin >> b;
	cout << endl;
	if (a > b) {
		unsigned long long temp = a;
		a = b;
		b = temp;
	}
	unsigned long long fib_prev = 0;
	unsigned long long fib_curr = 1;
	int current_index = 1;
	int i_idx = 0;              
	unsigned long long i_val = 0; 
	int j_idx = 0;              
	unsigned long long j_val = 0; 

	bool found_any = false;
	while (fib_curr <= b) {
		if (fib_curr >= a) {
			if (!found_any) {
				i_idx = current_index;
				i_val = fib_curr;
				found_any = true;
			}
			j_idx = current_index;
			j_val = fib_curr;
		}
		unsigned long long next_fib = fib_curr + fib_prev;
		fib_prev = fib_curr;
		fib_curr = next_fib;
		current_index++;
	}
	if (found_any) {
		cout << "\nResult: " << i_idx << ", " << i_val << ", " << j_idx << ", " << j_val << endl;
	}
	else {
		cout << "No Fibonacci numbers found in the range [" << a << ", " << b << "]." << endl;
	}
}

void task8() {
	int n;
	cout << "Give number to decode";
	cin >> n;
	int binary[32];
	int i = 0;
	while (n > 0) {
		binary[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << binary[j];
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