#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long recursivePower(int n) {
	if (n == 0) return 1;           
	return 2 * recursivePower(n - 1);
}

unsigned long long recursiveDoublePower(int n) {
	if (n == 0) return 2; // f(0) = 2^(2^0) = 2

	unsigned long long prev = recursiveDoublePower(n - 1);
	return prev * prev; // f(n) = f(n-1) * f(n-1)
}

long long iterativePower(int n) {
	long long result = 1;
	for (int i = 0; i < n; i++) {
		result *= 2;                
	}
	return result;
}

unsigned long long iterativeDoublePower(int n) {
	unsigned long long exponent = iterativePower(n);

	unsigned long long result = 1;
	for (unsigned long long i = 0; i < exponent; i++) {
		result *= 2;
	}
	return result;
}

long long factorial(int n) {
	long long res = 1;
	for (int i = 2; i <= n; i++) res *= i;
	return res;
}

long long iterativeBinomial(int n, int k) {
	if (k < 0 || k > n) return 0;
	return factorial(n) / (factorial(k) * factorial(n - k));
}

long long recursiveBinomial(int n, int k) {
	if (k == 0 || k == n) {
		return 1;
	}
	if (k < 0 || k > n) {
		return 0;
	}
	return recursiveBinomial(n - 1, k - 1) + recursiveBinomial(n - 1, k);
}

void calculateHanoiTime(int n) {
	double moves = pow(2, n) - 1;
	double secondsInYear = 31557600.0;
	double years = moves / secondsInYear;

	cout << "Total moves: " << moves << endl;
	cout << "Total years: " << years << endl;
}

int moveCounter = 0;
vector<vector<int>> pegs(3);

void printPegs() {
	for (int i = 0; i < 3; i++) {
		cout << "Peg " << i + 1 << ": [ ";
		for (int disk : pegs[i]) {
			cout << disk << " ";
		}
		cout << "]" << endl;
	}
	cout << "-----------------------" << endl;
}

void moveTower(int n, int from, int to, int aux) {
	if (n == 0) return;
	moveTower(n - 1, from, aux, to);
	int disk = pegs[from].back();
	pegs[from].pop_back();
	pegs[to].push_back(disk);
	moveCounter++;

	cout << "Move #" << moveCounter << ": Moving disk " << disk
		<< " from Peg " << from + 1 << " to Peg " << to + 1 << endl;
	printPegs();
	moveTower(n - 1, aux, to, from);
}

void generateSequences(int n, int k, vector<int>& current) {
	if (current.size() == k) {
		for (int i = 0; i < k; i++) {
			cout << current[i] << (i == k - 1 ? "" : ", ");
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		current.push_back(i);
		generateSequences(n, k, current);
		current.pop_back();
	}
}


int task1() {
	int n;
	cin >> n;
	cout << "recursive output: " << recursivePower(n) << endl;
	cout << "iterative output: " << iterativePower(n) << endl;
	return 0;
}

int task2() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	//Note: n > 5 will cause an overflow for a 64 - bit long long
	cout << "Recursive 2^(2^n): " << recursiveDoublePower(n) << endl;
	cout << "Iterative 2^(2^n): " << iterativeDoublePower(n) << endl;
	return 0;
}

int task3() {
	int n, k;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter k: ";
	cin >> k;
	cout << "iterative output: " << iterativeBinomial(n, k) << endl;	
	cout << "recursive output: " << recursiveBinomial(n, k) << endl;	
	return 0; 
}

int task4() {
	int n;
	cin >> n;
	cout << "recursive output: " << recursivePower(n) << endl;
	return 0;
}

void task5() {
	int n;
	cout << "Enter number of disks: ";
	cin >> n;

	moveCounter = 0;
	pegs[0].clear(); pegs[1].clear(); pegs[2].clear();
	for (int i = 1; i <= n; i++) {
		pegs[0].push_back(i);
	}
	pegs[0].clear();
	for (int i = 1; i <= n; i++) {
		pegs[0].insert(pegs[0].begin(), i);
	}

	cout << "Initial State:" << endl;
	printPegs();

	moveTower(n, 0, 2, 1);
}

void task6() {
	int n, k;
	cout << "Enter n (range 1..n) and k (length): ";
	cin >> n >> k;
	vector<int> current;
	generateSequences(n, k, current);
}

int main() {
	int x;
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
	}
	return 0;
}