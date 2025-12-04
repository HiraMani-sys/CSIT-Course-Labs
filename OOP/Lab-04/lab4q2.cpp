#include <iostream>
using namespace std;

// Base class
class Lecturer {
protected:
    string name;
    int id;

public:
    int courseId;
    string course_Name;

    Lecturer(string n, int i, int cId, string cName)
        : name(n), id(i), courseId(cId), course_Name(cName) {}

    // Virtual function to be overridden
    virtual void displayDetails() {
        cout << "Lecturer Name: " << name << endl;
        cout << "Lecturer ID: " << id << endl;
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << course_Name << endl;
    }
};

// Derived class: PartTimeFaculty
class PartTimeFaculty : public Lecturer {
private:
    float payPerHour;

public:
    PartTimeFaculty(string n, int i, int cId, string cName, float pph)
        : Lecturer(n, i, cId, cName), payPerHour(pph) {}

    void displayDetails() override {
        Lecturer::displayDetails();
        cout << "Part Time Faculty Pay Per Hour: " << payPerHour << endl;
    }
};

// Derived class: FullTimeFaculty
class FullTimeFaculty : public Lecturer {
private:
    float salary;

public:
    FullTimeFaculty(string n, int i, int cId, string cName, float sal)
        : Lecturer(n, i, cId, cName), salary(sal) {}

    void displayDetails() override {
        Lecturer::displayDetails();
        cout << "Full Time Faculty Salary: " << salary << endl;
    }
};

// Main function
int main() {
    Lecturer* faculty;

    PartTimeFaculty pt("Alice", 101, 501, "Computer Science", 500.0);
    FullTimeFaculty ft("Bob", 102, 502, "Mathematics", 40000.0);

    cout << "--- Part-Time Faculty ---\n";
    faculty = &pt;
    faculty->displayDetails();  // Calls overridden method in PartTimeFaculty

    cout << "\n--- Full-Time Faculty ---\n";
    faculty = &ft;
    faculty->displayDetails();  // Calls overridden method in FullTimeFaculty

    return 0;
}

