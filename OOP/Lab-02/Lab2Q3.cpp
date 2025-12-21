#include<iostream>
using namespace std;
class Student{
	int id;
	double marks;
	public:
	Student(){
		cout << "enter the id:";
		cin >> id;
		cout << endl << "enter the marks";
		cin >> marks;
	}
	Student(int i, double m){
		id=i;
		marks=m;
	}
	Student(const Student &s){
		id=s.id;
		marks=s.marks;
	}
	void display(){
		cout << "Student ID:" << id << endl;
		cout << "Marks:" << marks << endl;
	}
};
int main(){
	cout << "Default Constructor" << endl;
	Student obj1;
	obj1.display();
	cout << "Paramaterized Constructor" << endl;
	Student obj2(102,75);
	obj2.display();
	cout << "Copy Constructor" << endl;
	Student obj3=obj2;
	obj3.display();
	return 0;
}
