#include <iostream>
#include <iomanip> // For manipulators

using namespace std;

int main() {
    double value = 123.456789;
    int integer_val = 15;

    cout << "--- setw and setfill ---" << endl;
    cout << setw(10) << setfill('*') << "Data" << endl;

    // Reset fill to space explicitly
    cout << setw(8) << right << setfill(' ') << 99 << endl;

    cout << "\n--- setprecision ---" << endl;
    cout << "Default: " << value << endl;
    cout << setprecision(4) << value << endl;
    cout << fixed << setprecision(2) << value << endl; // Fixed decimal places

    cout << "\n--- setbase ---" << endl;
    cout << "Decimal: " << integer_val << endl;
    cout << "Hexadecimal: " << hex << integer_val << endl;
    cout << "Octal: " << oct << integer_val << endl;
    cout << "Decimal (restored): " << dec << integer_val << endl;

    return 0;
}

