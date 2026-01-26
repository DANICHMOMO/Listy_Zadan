#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int task16() {
	string s;
	if (!(cin >> s)) { 
		cout << 0 << endl; 
		return 0; 
	}

	int n = static_cast<int>(s.size());
	int maxLen = 0;
	auto expand = [&](int l, int r) {
		while (l >= 0 && r < n && s[l] == s[r]) 
		{ 
			--l; 
			++r; 
		}
		return r - l - 1;
		};

	for (int i = 0; i < n; ++i) {
		maxLen = max(maxLen, expand(i, i));     // odd
		maxLen = max(maxLen, expand(i, i + 1)); // even
	}

	cout << maxLen << endl;
	return 0;
}

int task17() {
	int n;
	if (!(cin >> n)) return 0;

	auto isPrime = [](int x) -> bool {
		if (x <= 1) return false;
		if (x == 2) return true;
		if (x % 2 == 0) return false;
		int limit = static_cast<int>(sqrt(x));
		for (int i = 3; i <= limit; i += 2) {
			if (x % i == 0) return false;
		}
		return true;
		};

	int candidate = n + 1;
	while (!isPrime(candidate)) {
		++candidate;
	}

	cout << candidate << endl;
	return 0;
}

int task18() {
	string a, b, output;
	cout << "Give first word: ";
	getline(cin >> ws, a);
	cout << "Give second word: ";
	getline(cin >> ws, b);
	size_t min_size = min(a.size(), b.size());
	for (size_t i = 0; i < min_size; ++i) {
		if (a[i] == b[i]) output.push_back(a[i]);
		else break;
	}

	cout << output << endl;
	return 0;
}


int task19() {
	int n;
	if (!(cin >> n)) return 0;
	vector<long long> times;
	times.reserve(n);
	for (int i = 0; i < n; ++i) {
		long long t;
		cin >> t;
		times.push_back(t);
	}
	long long current_sum = 0;
	long long max_wait = 0;
	for (int i = 0; i < n; ++i) {
		long long wait = current_sum;      
		if (wait > max_wait) max_wait = wait;
		current_sum += times[i];           
	}

	cout << max_wait << endl;
	return 0;
}

int task20() {
	int n;
	if (!(cin >> n)) return 0;

	struct Task { int duration; int priority; };
	vector<Task> tasks;
	tasks.reserve(n);
	for (int i = 0; i < n; ++i) {
		int duration, priority;
		cin >> duration >> priority;
		tasks.push_back({ duration, priority });
	}
	sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
		if (a.priority != b.priority) return a.priority > b.priority;
		return a.duration < b.duration;
		});

	long long total_time = 0;
	long long current_start = 0;
	long long max_wait = 0;

	for (const auto& t : tasks) {
		if (current_start > max_wait) max_wait = current_start;
		current_start += t.duration;
		total_time += t.duration;
	}
	cout << total_time << " " << max_wait << endl;
	return 0;
}

int main() {
	int x;
	cin >> x;
	switch (x) {
	case 16:
		task16();
		break;
	case 17:
		task17();
		break;
	case 18:
		task18();
		break;
	case 19:
		task19();
		break;
	case 20:
		task20();
		break;
	}
return 0;
}