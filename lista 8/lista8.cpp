#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void task1() {
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
	cout << "Last in Array: ";
	cout << a.front() << "\n";
	cout << "First in Array: ";
	cout << a.back();
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
	vector<int> a;
	int x, sum;
	double geo_mean_buffer, har_mean_buffer;
	cout << "Enter numbers:" << endl;
	while (cin >> x) {
		if (x == 0) break;
		a.push_back(x);
	}
	for (int i = 0; i < a.size(); i++)
	{
		sum = sum + a.at(i);
		har_mean_buffer = har_mean_buffer + 1 / a.at(i);
		geo_mean_buffer = geo_mean_buffer * a.at(i);
	}

	cout << "Sum of integers is: " << sum << endl;
	cout << "Geometrical mean of integers is: " << pow(geo_mean_buffer, 1 / a.size()) << endl;
	cout << "Harmonical mean of integers is: " << a.size() / har_mean_buffer << endl;
}

void task4() {
	long long a, b;
	if (!(cin >> a >> b)) return;

	if (a < 2) a = 2;
	if (a > b) return;

	long long limit = sqrt(b);
	vector<bool> is_small_prime(limit + 1, true);
	vector<long long> small_primes;

	for (long long p = 2; p <= limit; p++) {
		if (is_small_prime[p]) {
			small_primes.push_back(p);
			for (long long i = p * p; i <= limit; i += p)
				is_small_prime[i] = false;
		}
	}

	vector<bool> is_prime_in_range(b - a + 1, true);

	for (long long p : small_primes) {
		long long start = (a + p - 1) / p * p;
		if (start < p * p) start = p * p;

		for (long long j = start; j <= b; j += p) {
			is_prime_in_range[j - a] = false;
		}
	}

	for (long long i = 0; i <= b - a; i++) {
		if (is_prime_in_range[i]) {
			cout << a + i << "\n";
		}
	}
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
	long long day, month, year, hour, minute, second;
	if (!(cin >> day >> month >> year >> hour >> minute >> second)) return;

	long long prev_years = year - 1;
	long long total_days = prev_years * 365 + (prev_years / 4) - (prev_years / 100) + (prev_years / 400);

	int days_in_months[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		days_in_months[2] = 29;
	}

	for (int i = 1; i < month; i++) {
		total_days += days_in_months[i];
	}

	total_days += (day - 1);

	long long total_hours = total_days * 24 + hour;
	long long total_minutes = total_hours * 60 + minute;
	long long total_seconds = total_minutes * 60 + second;

	cout << total_days << "\n";
	cout << total_hours << "\n";
	cout << total_minutes << "\n";
	cout << total_seconds << "\n";
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
	default:
		main();
		break;
	}
	return 0;
}