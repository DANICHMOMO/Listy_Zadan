#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isBinaryDigit(char c) {
    return c == '0' || c == '1';
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int digit(int i, int n) {
    return (n / (int)pow(10, i)) % 10;
}

int task1() {
    cin.ignore();

    char c;
    double totalSum = 0.0;

    while (cin.get(c) && c != ';') {
        bool isNegative = false;

        if (c == '-') {
            char next = cin.peek();
            if (isBinaryDigit(next)) {
                isNegative = true;
                cin.get(c);
            }
            else {
                continue;
            }
        }

        if (isBinaryDigit(c)) {
            double currentNumber = 0.0;

            do {
                currentNumber = currentNumber * 2 + (c - '0');
                cin.get(c);
            } while (isBinaryDigit(c));

            if (c == ',') {
                double placeValue = 0.5;
                cin.get(c);
                while (isBinaryDigit(c)) {
                    if (c == '1') {
                        currentNumber += placeValue;
                    }
                    placeValue /= 2.0;
                    cin.get(c);
                }
            }

            if (isNegative) currentNumber = -currentNumber;
            totalSum += currentNumber;

            if (c == ';') break;
        }
    }

    cout << totalSum << endl;
    return 0;
}

int task2() {
    int n;
    cin >> n;

    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 2) cout << n;
    cout << endl;
    return 0;
}

int task3() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}

int task4() {
    int n;
    cin >> n;

    int sum = 0;
    int length = 0;
    int temp = n;

    while (temp > 0) {
        temp /= 10;
        length++;
    }

    for (int i = 0; i < length; i++) {
        sum += digit(i, n);
    }

    if (sum % 2 == 0) {
        cout << "EVEN" << endl;
    }
    else {
        cout << "ODD" << endl;
    }
    return 0;
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
    }
    return 0;
}