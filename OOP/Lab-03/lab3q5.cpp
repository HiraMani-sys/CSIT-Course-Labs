/*Write a program to create a class named &quot;Height&quot; with data members meter(int) and centimeter(int).
Overload the binary + operator using friend function to add two height h1 and h2.*/

#include <iostream>
using namespace std;

class Height {
private:
    int meter;
    int centimeter;

public:
    // Constructor
    Height(int m = 0, int cm = 0) : meter(m), centimeter(cm) {}

    // Friend function to overload + operator
    friend Height operator+(Height h1, Height h2);

    // Display function
    void display() const {
        cout << "Height: " << meter << " meters and " << centimeter << " centimeters" << endl;
    }
};

// Definition of overloaded + operator using friend function
Height operator+(Height h1, Height h2) {
    int totalMeters = h1.meter + h2.meter;
    int totalCentimeters = h1.centimeter + h2.centimeter;

    // Convert excess centimeters to meters
    totalMeters += totalCentimeters / 100;
    totalCentimeters %= 100;

    return Height(totalMeters, totalCentimeters);
}

int main() {
    Height h1(1, 75);  // 1 meter 75 cm
    Height h2(2, 50);  // 2 meters 50 cm

    cout << "First height: ";
    h1.display();

    cout << "Second height: ";
    h2.display();

    Height h3 = h1 + h2;  // Add the heights using overloaded + operator

    cout << "Total height: ";
    h3.display();

    return 0;
}

