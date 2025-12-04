#include <iostream>
using namespace std;

// Class for basic Euclidean GCD algorithm
class EuclideanGCD {
public:
    int computeGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

// Class for Extended Euclidean Algorithm
class ExtendedEuclidean {
public:
    int computeExtendedGCD(int a, int b, int &x, int &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int gcd = computeExtendedGCD(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return gcd;
    }
};

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    EuclideanGCD euclid;
    ExtendedEuclidean extended;

    int gcd = euclid.computeGCD(a, b);
    cout << "GCD using Euclidean Algorithm: " << gcd << endl;

    int x, y;
    int extGCD = extended.computeExtendedGCD(a, b, x, y);
    cout << "GCD using Extended Euclidean Algorithm: " << extGCD << endl;
    cout << "Coefficients x and y such that a*x + b*y = gcd: "
         << x << " " << y << endl;

    return 0;
}

