#include <iostream>
#include "myheader.h"

using namespace std;

int main() {
    greet(); // Function from header
    int sum = add(10, 20); // Function from header
    cout << "The sum is: " << sum << endl;
    return 0;
}

