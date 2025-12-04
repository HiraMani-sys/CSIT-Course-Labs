#include<iostream>
using namespace std;

// Abstract base class
class fmachine {
public:
    virtual void getdata() = 0;       // Pure virtual functions
    virtual void putdata() = 0;
    virtual void displaydata() = 0;
    virtual ~fmachine() {}            // Virtual destructor for proper cleanup
};

// Derived class
class Aero_plane : public fmachine {
private:
    string model;
    int capacity;

public:
    void getdata() override {
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter capacity: ";
        cin >> capacity;
    }

    void putdata() override {
        cout << "Model: " << model << "\n";
        cout << "Capacity: " << capacity << "\n";
    }

    void displaydata() override {
        cout << "Displaying Aero-plane details...\n";
        putdata();
    }
};

int main() {
    fmachine* fptr = new Aero_plane();   // Dynamic memory allocation and base pointer
    fptr->getdata();                     // Dynamic binding
    fptr->displaydata();                 // Dynamic binding

    delete fptr;                         // Free allocated memory
    return 0;
}
