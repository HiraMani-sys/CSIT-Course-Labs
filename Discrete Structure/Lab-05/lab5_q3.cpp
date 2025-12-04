 #include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int power(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

bool isProbablyPrime(int n, int a) {
    if (n == 2 || n == 3) return true;
    if (n <= 1 || gcd(a, n) != 1) return false;
    return power(a, n - 1, n) == 1;
}

int main() {
    int num = 561; // Number to test
    int base = 2; // Base for Fermat's test

    if (isProbablyPrime(num, base))
        cout << num << " is probably prime.\n";
    else
        cout << num << " is composite.\n";

    return 0;
}

