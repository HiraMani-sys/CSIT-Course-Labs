#include <iostream>
using namespace std;

void primeFactors(int n) {
    cout << "Prime factors of " << n << " are: ";

    // Divide out all 2s
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Try odd numbers starting from 3
    for (int i = 3; i*i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // If n is still greater than 2, it must be prime
    if (n > 2)
        cout << n;

    cout << endl;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number <= 1)
        cout << "No prime factors for " << number << endl;
    else
        primeFactors(number);

    return 0;
}

