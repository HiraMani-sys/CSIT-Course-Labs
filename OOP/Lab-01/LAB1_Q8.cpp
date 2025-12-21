#include <iostream>

// Using directive here (for the last part)
using namespace std;

int main() {
    // Using the :: operator (fully qualified names)
    std::cout << "--- Using :: operator ---" << std::endl;
    std::cout << "Enter an integer using :: operator: ";
    int num_op;
    std::cin >> num_op;
    std::cout << "You entered: " << num_op << std::endl << std::endl;

    // Using declaration (bring specific names into scope)
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "--- Using declaration ---" << endl;
    cout << "Enter an integer using using declaration: ";
    int num_decl;
    cin >> num_decl;
    cout << "You entered: " << num_decl << endl << endl;

    // Using directive (all names from std available)
    cout << "--- Using directive ---" << endl;
    cout << "Enter an integer using using directive: ";
    int num_dir;
    cin >> num_dir;
    cout << "You entered: " << num_dir << endl;

    return 0;
}

