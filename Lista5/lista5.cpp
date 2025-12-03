#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void task1() {
	int s, n;
	cout << "Enter N: ";
	cin >> n;
	cout << "Enter S: ";
	cin >> s;
	int i;
	if (n % 2 == 0) {
		i = n;
	}
	else {
		i = n + 1;
	}

	int output = 0;
	int x = 0;

	while (output + i <= s) {
		output += i;
		x++;
		i += 2;
	}
	cout << output << endl;
	cout << i / x;
}

void task2() {
	vector<int> a;
	int x;
	while (cin >> x && x != 0) {
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

	bool output = false;
	for (size_t i = 1; i < a.size(); i++) {
		if (a[i] == a[i - 1] + 1) {
			output = true;
			break;
		}
	}

	if (output) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

void task3() {
	vector<int> a;
	vector<int> b;
	vector<int> c;
	int x, count = 0;
	cout << "Enter array size: ";
	cin >> x;
	cout << "Enter first array: ";
	int aInput;
	for (int i = 0; i < x; i++)
	{
		cin >> aInput;
		a.push_back(aInput);
	}
	cout << "Enter secound array: ";
	int bInput;
	for (int i = 0; i < x; i++)
	{
		cin >> bInput;
		b.push_back(bInput);
	}
	for (int i = 0; i < x; i++)
	{
		if (a[i] == b[i]) {
			c.push_back(a.at(i));
			count++;
		}
	}
	cout << count << endl;
	cout << "Array is: ";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c.at(i) << ", ";
	}
}

void task4() {
	int n = 0, k = 0;
	vector<int> a;
	int aInput;
	cout << "Enter size of array: ";
	cin >> n;
	cout << "Enter k: ";
	cin >> k;
	cout << "Give numbers of array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> aInput;
		a.push_back(aInput);
	}
	cout << "\nArray values lower than k: ";
	for (int i = 0; i < n; i++)
	{
		if (a.at(i) < k) {
			cout << a.at(i) << ", ";
		}
	}
	cout << "\nArray values greater than k: ";
	for (int i = 0; i < n; i++)
	{
		if (a.at(i) > k) {
			cout << a.at(i) << ", ";
		}
	}
}

void task5() {
	vector<int> a;
	int x;
	cout << "Enter numbers:" << endl;
	while (cin >> x) {
		if (x == 0) break;
		if (x == 1 || x == 2) {
			a.push_back(x);
		}
	}
	bool isPalindrome = true;
	int n = a.size();
	for (int i = 0; i < n / 2; i++) {
		if (a[i] != a[n - 1 - i]) {
			isPalindrome = false;
			break;
		}
	}
	if (isPalindrome && n > 0)
		cout << "Palindrome.";
	else
		cout << "Not Palindrome.";
}

void task6() {
	vector<int> a;
	int count = 0, n, x;
	cout << "Enter numbers:" << endl;
	while (cin >> x) {
		if (x == 0) break;
		a.push_back(x);
	}
	for (int i = 0; i < a.size() - 2; i++)
	{
		if (a[i] + a[i + 1] == a[i + 2])
		{
			count++;
		}
	}
	cout << count;
}

void task7() {
	vector<int> a;
	int x;
	cout << "Enter numbers:" << endl;
	while (cin >> x) {
		if (x == 0) break;
		if (x == 1 || x == 2) {
			a.push_back(x);
		}
	}
	int n = a.size();
	if (n % 2 != 0) {
		cout << "NO (Length is odd, cannot be w+w)" << endl;
	}
	if (n == 0) {
		cout << "NO (Empty)" << endl;
	}
	int half = n / 2;
	bool isConcatenation = true;
	for (int i = 0; i < half; i++) {
		if (a[i] != a[i + half]) {
			isConcatenation = false;
			break;
		}
	}

	if (isConcatenation) {
		cout << "YES (The word is w + w)" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

void task8() {
	vector<int> a;
	int x;
	cout << "Podaj ciag zer i jedynek (zakoncz 2):" << endl;
	while (cin >> x) {
		if (x == 2) break;
		if (x == 0 || x == 1) {
			a.push_back(x);
		}
	}
	int remainder = 0;
	for (int bit : a) {
		remainder = (remainder * 2 + bit) % 3;
	}
	if (remainder == 0 && !a.empty()) {
		cout << "TAK (Podzielna przez 3)" << endl;
	}
	else {
		cout << "NIE (Reszta wynosi: " << remainder << ")" << endl;
	}
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