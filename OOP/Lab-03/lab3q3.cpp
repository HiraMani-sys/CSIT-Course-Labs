/*Write a program to overload the unary minus operator using friend function.*/

#include <iostream>
using namespace std;

class Student {
private:
    int visits;

public:
    Student() : visits(0) {}

    // Overload postfix increment operator
    Student operator++(int) {
        Student temp = *this;
        visits++;  // Increase the visit count
        return temp;
    }

    void display() const {
        cout << "Number of visits: " << visits << endl;
    }
};

int main() {
    Student s1;

    cout << "Initial visits: ";
    s1.display();

    // Simulate student visiting multiple times
    s1++;
    s1++;
    s1++;

    cout << "After 3 visits: ";
    s1.display();

    return 0;
}

