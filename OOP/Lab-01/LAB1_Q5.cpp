#include <iostream>

using namespace std;

int main() {
    double doubleVar = 15.75;
    int intVar;

    // C-style cast
    intVar = (int)doubleVar;
    cout << "Original doubleVar: " << doubleVar << endl;
    cout << "After C-style cast to int (intVar): " << intVar << endl;

    float floatVar = 12.34f;
    int intResult;

    // static_cast
    intResult = static_cast<int>(floatVar);
    cout << "Original floatVar: " << floatVar << endl;
    cout << "After static_cast to int (intResult): " << intResult << endl;

    return 0;
}

