#include<iostream>
using namespace std;

// Virtual base class
class student {
protected:
    string name;
    int roll_no;

public:
    void read() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll_no;
    }

    void display() {
        cout << "Name: " << name << "\nRoll Number: " << roll_no << endl;
    }
};

// Derived class test
class test : virtual public student {
protected:
    float marks1, marks2;

public:
    void readTestMarks() {
        cout << "Enter marks for subject 1 and 2: ";
        cin >> marks1 >> marks2;
    }

    void displayTestMarks() {
        cout << "Subject 1 Marks: " << marks1 << "\nSubject 2 Marks: " << marks2 << endl;
    }
};

// Derived class sports
class sports : virtual public student {
protected:
    float score;

public:
    void readSportsScore() {
        cout << "Enter sports score: ";
        cin >> score;
    }

    void displaySportsScore() {
        cout << "Sports Score: " << score << endl;
    }
};

// Derived class result
class result : public test, public sports {
    float total;

public:
    void calculateTotal() {
        total = marks1 + marks2 + score;
    }

    void displayResult() {
        display(); // from student
        displayTestMarks();
        displaySportsScore();
        cout << "Total Score (Test + Sports): " << total << endl;
    }
};

int main() {
    result r;
    r.read();
    r.readTestMarks();
    r.readSportsScore();
    r.calculateTotal();
    r.displayResult();

    return 0;
}
