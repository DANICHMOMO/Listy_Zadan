#include<iostream>
#include<cmath>
#include<vector>
#include<functional>
#include<random>
#include<sstream>
#include<string>
#include<map>
#include<queue>
#include<climits>

using namespace std;

void task1() {
	int n;
	cout << "Enter number of elements: ";
	cin >> n;

	if (n <= 0) {
		cout << "Longest sequence length: 0" << endl;
	}

	vector<int> a(n);
	cout << "Enter elements separated by space: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int maxLength = 1;
	int currentLength = 1;

	for (size_t i = 1; i < a.size(); i++) {
		if (a[i] == a[i - 1]) {
			currentLength++;
		}
		else {
			if (currentLength > maxLength) {
				maxLength = currentLength;
			}
			currentLength = 1;
		}
	}

	if (currentLength > maxLength) {
		maxLength = currentLength;
	}

	cout << "Longest sequence length: " << maxLength << endl;
}

void task2() {
	string text;
	int caesarShift;
	int railDepth;

	cout << "Enter text to encrypt: ";
	getline(cin, text);

	cout << "Enter Caesar shift value: ";
	cin >> caesarShift;

	cout << "Enter Rail Fence depth: ";
	cin >> railDepth;

	string caesarResult = text;
	for (size_t i = 0; i < caesarResult.length(); i++) {
		if (isalpha(caesarResult[i])) {
			char base = isupper(caesarResult[i]) ? 'A' : 'a';
			int val = (caesarResult[i] - base + caesarShift) % 26;
			if (val < 0) val += 26;
			caesarResult[i] = base + val;
		}
	}

	string railResult = "";
	if (railDepth > 1) {
		vector<string> rails(railDepth);
		int row = 0;
		bool down = false;

		for (char c : text) {
			rails[row].push_back(c);

			if (row == 0 || row == railDepth - 1) {
				down = !down;
			}

			row += down ? 1 : -1;
		}

		for (int i = 0; i < railDepth; i++) {
			railResult += rails[i];
		}
	}
	else {
		railResult = text;
	}

	cout << "Original Text:     " << text << endl;
	cout << "Caesar Cipher:     " << caesarResult << endl;
	cout << "Rail Fence Cipher: " << railResult << endl;
}

void task3() {
	int n;
	cout << "Enter number of elements: ";
	cin >> n;

	vector<int> elements(n);
	cout << "Enter elements: ";
	for (int i = 0; i < n; i++) {
		cin >> elements[i];
	}

	map<int, int> counts;
	for (int x : elements) {
		counts[x]++;
	}

	auto newEnd = remove_if(elements.begin(), elements.end(), [&counts](int x) {
			return counts[x] > 1;
		}
	);

	elements.erase(newEnd, elements.end());

	cout << "Remaining elements: ";
	for (int x : elements) {
		cout << x << " ";
	}
	cout << endl;
}

void task4() {
	int n, X;

	cout << "Enter the number of elements: ";
	cin >> n;

	vector<int> t(n);
	cout << "Enter the elements: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}

	cout << "Enter the target sum X: ";
	cin >> X;

	cout << "Pairs of indices:" << endl;
	bool found = false;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (t[i] + t[j] == X) {
				cout << "(" << i << ", " << j << ")" << endl;
				found = true;
			}
		}
	}

	if (!found) {
		cout << "No pairs found." << endl;
	}
}

void task5() {
	string text;
	getline(cin, text);
	int a = 0;
	for (char letter : text) {
		if ((letter == 'a') || (letter == 'e') || (letter == 'u') || (letter == 'i') || (letter == 'o') || (letter == 'y')) {
			a++;
		}
	}
	cout << a << endl;
}

void task6() {
	int n;
	cout << "Enter number of elements: ";
	cin >> n;

	vector<int> vec(n);
	cout << "Enter elements: ";
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	for (size_t i = 0; i + 1 < vec.size(); i += 2) {
		swap(vec[i], vec[i + 1]);
	}

	cout << "Swapped vector: ";
	for (int x : vec) {
		cout << x << " ";
	}
	cout << endl;
}

void task7() {
	vector<int> t = { 5, 0, 0, 3, 0, 4, 0, 7 };
	int n = t.size();
	int lastNonZeroFoundAt = 0;

	for (int i = 0; i < n; i++) {
		if (t[i] != 0) {
			swap(t[lastNonZeroFoundAt], t[i]);
			lastNonZeroFoundAt++;
		}
	}

	cout << "Modified array: ";
	for (int i = 0; i < n; i++) {
		cout << t[i] << " ";
	}
	cout << endl;
}

void task8() {
	string s1, s2;

	cout << "Enter first string: ";
	cin >> s1;
	cout << "Enter second string: ";
	cin >> s2;

	if (s1.length() != s2.length()) {
		cout << "Not anagrams (different lengths)." << endl;
	}
	else {
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		if (s1 == s2) {
			cout << "The strings are anagrams." << endl;
		}
		else {
			cout << "The strings are not anagrams." << endl;
		}
	}
}

void task9() {
	string mask, text;

	cout << "Enter mask: ";
	cin >> mask;
	cout << "Enter text: ";
	cin >> text;

	int t = 0;
	int m = 0;
	int starIdx = -1;
	int matchIdx = -1;

	while (t < text.length()) {
		if (m < mask.length() && (mask[m] == '?' || mask[m] == text[t])) {
			t++;
			m++;
		}
		else if (m < mask.length() && mask[m] == '*') {
			starIdx = m;
			matchIdx = t;
			m++;
		}
		else if (starIdx != -1) {
			m = starIdx + 1;
			matchIdx++;
			t = matchIdx;
		}
		else {
			cout << "Result: not matched" << endl;
		}
	}

	while (m < mask.length() && mask[m] == '*') {
		m++;
	}

	if (m == mask.length()) {
		cout << "Result: matched" << endl;
	}
	else {
		cout << "Result: not matched" << endl;
	}
}

void task10() {
	string password;

	cout << "Enter 5-character password: ";
	cin >> password;

	if (password.length() != 5) {
		cout << "Error: Password must have exactly 5 characters!" << endl;
	}

	const char charset[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	const size_t max_index = (sizeof(charset) - 1);

	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> distribution(0, max_index);

	string salt = "";
	for (size_t i = 0; i < 16; ++i) {
		salt += charset[distribution(generator)];
	}

	string saltedPassword = salt + password;

	hash<string> hasher;
	size_t hashValue = hasher(saltedPassword);
	cout << "Password:      " << password << endl;
	cout << "Salt:          " << salt << endl;
	cout << "Salted Input:  " << saltedPassword << endl;
	cout << "Hash Result:   " << hashValue << endl;
}

void task11() {
	int vertices, edges_count, start_node;

	cout << "Enter number of vertices and edges: ";
	cin >> vertices >> edges_count;

	vector<vector<pair<int, int>>> graph(vertices + 1);

	cout << "Enter edges (source destination weight):" << endl;
	for (int i = 0; i < edges_count; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	cout << "Enter starting vertex: ";
	cin >> start_node;

	vector<int> dist(vertices + 1, INT_MAX);
	dist[start_node] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start_node });

	while (!pq.empty()) {
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (d > dist[u]) continue;

		for (auto& edge : graph[u]) {
			int v = edge.first;
			int weight = edge.second;

			if (dist[u] + weight < dist[v]) {
				dist[v] = dist[u] + weight;
				pq.push({ dist[v], v });
			}
		}
	}

	cout << "Shortest distances from vertex " << start_node << ":" << endl;
	for (int i = 1; i <= vertices; i++) {
		if (dist[i] == INT_MAX)
			cout << "Vertex " << i << ": Unreachable" << endl;
		else
			cout << "Vertex " << i << ": " << dist[i] << endl;
	}
}

void task12() {
	double a, h;

	cout << "Enter base edge length (a): ";
	cin >> a;
	cout << "Enter pyramid height (h): ";
	cin >> h;

	double Pp = (3 * pow(a, 2) * sqrt(3)) / 2;
	double V = (Pp * h) / 3;

	double r = (a * sqrt(3)) / 2;
	double hs = sqrt(pow(h, 2) + pow(r, 2));
	double Pb = 3 * a * hs;
	double Pc = Pp + Pb;

	cout << "Volume: " << V << endl;
	cout << "Total Surface Area: " << Pc << endl;
}

void task13() {
	double numbers[5];
	double sum = 0;
	double reciprocalSum = 0;

	cout << "Enter 5 positive real numbers:" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> numbers[i];
		sum += numbers[i];
		reciprocalSum += (1.0 / numbers[i]);
	}

	double arithmeticMean = sum / 5.0;
	double harmonicMean = 5.0 / reciprocalSum;

	cout << "Arithmetic Mean: " << arithmeticMean << endl;
	cout << "Harmonic Mean: " << harmonicMean << endl;
}

void task14() {
	int a, b, c;
	int delta, x1, x2;
	cin >> a >> b >> c;
	if(a != 0){
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
	case 9:
		task9();
		break;
	case 10:
		task10();
		break;
	case 11:
		task11();
		break;
	case 12:
		task12();
		break;
	case 13:
		task13();
		break;
	case 14:
		task14();
		break;
	}
	return 0;
}