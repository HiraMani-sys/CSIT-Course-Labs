#include <iostream>
using namespace std;

// Find modular inverse of a modulo m using brute-force
int modInverse(int a, int m) {
    for (int x = 1; x < m; ++x) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // No inverse found
}

int chineseRemainder(int a1, int m1, int a2, int m2) {
    int M = m1 * m2;
    int M1 = M / m1;
    int M2 = M / m2;

    int inv1 = modInverse(M1, m1);
    int inv2 = modInverse(M2, m2);

    int result = (a1 * M1 * inv1 + a2 * M2 * inv2) % M;
    return result;
}

int main() {
    int a1 = 2, m1 = 3;
    int a2 = 3, m2 = 5;

    int x = chineseRemainder(a1, m1, a2, m2);
    cout << "x = " << x << endl;

    return 0;
}

