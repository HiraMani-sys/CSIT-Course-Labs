/*Write a program to overload the unary minus operator using friend function.*/

#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v) : value(v) {}

    // Friend function declaration
    friend Number operator-(Number);

    // Display function
    void display() {
        cout << "Value: " << value << endl;
    }
};

// Friend function definition
Number operator-(Number obj) {
    return Number(-obj.value);  // Negates the value
}

int main() {
    Number num1(42);
    cout << "Original number: ";
    num1.display();

    Number num2 = -num1;
    cout << "After applying unary minus: ";
    num2.display();

    return 0;
}

