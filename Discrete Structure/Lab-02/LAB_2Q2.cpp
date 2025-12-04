#include <iostream>
#include <string>
#include <bitset>
using namespace std;

// Convert binary string to decimal manually
int binaryToDecimal(const string& bin) {
    int result = 0;
   for (int i = 0; i < bin.length(); ++i) {
    result = result * 2 + (bin[i] - '0');
}
    return result;
}

// Bitwise binary addition
int addBinary(int a, int b) {
    while (b != 0) {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

// Binary multiplication using shifts
int multiplyBinary(int a, int b) {
    int result = 0;
    while (b != 0) {
        if (b & 1) result = addBinary(result, a);
        a <<= 1;
        b >>= 1;
    }
    return result;
}

int main() {
    string input1, input2;

    cout << "Enter first binary number (e.g. 1011): ";
    cin >> input1;
    cout << "Enter second binary number: ";
    cin >> input2;

    int num1 = binaryToDecimal(input1);
    int num2 = binaryToDecimal(input2);

    int sum = addBinary(num1, num2);
    int product = multiplyBinary(num1, num2);

    cout << "\nAddition result:       " << bitset<16>(sum) << " (decimal: " << sum << ")\n";
    cout << "Multiplication result: " << bitset<16>(product) << " (decimal: " << product << ")\n";

    return 0;
}

