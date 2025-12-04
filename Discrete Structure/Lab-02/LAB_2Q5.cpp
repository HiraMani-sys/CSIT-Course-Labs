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

// Try small values of x to find solution
void findSolution(int a, int b, int m) {
    for (int x = 0; x < m; ++x) {
        if ((a * x) % m == b % m) {
            cout << "Solution: x = " << x << endl;
            return;
        }
    }
    cout << "No solution exists." << endl;
}

int main() {
    int a, b, m;
    cout << "Solve a·x = b (mod m)" << endl;
    cout << "Enter a, b, and m: ";
    cin >> a >> b >> m;

    if (gcd(a, m) == 1) {
        findSolution(a, b, m);
    } else {
        cout << "Note: a and m are not coprime. Multiple or no solutions might exist." << endl;
        findSolution(a, b, m);
    }

    return 0;
}

