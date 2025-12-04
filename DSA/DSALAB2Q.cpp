#include <iostream>
using namespace std;

#define MAX 5   // Maximum size of stack

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    // Check overflow
    bool isOverflow() {
        return top == MAX - 1;
    }

    // Check underflow
    bool isUnderflow() {
        return top == -1;
    }

    // Push operation
    void push(int x) {
            arr[++top] = x;
            cout << x << " pushed into stack." << endl;
    }

    // Pop operation
    void pop() {
        if (isUnderflow()) {
            cout << " Stack Underflow! Nothing to pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Peek operation
    void peek() {
        if (isUnderflow()) {
            cout << " Stack is empty." << endl;
        } else {
            cout << " Top element is: " << arr[top] << endl;
        }
    }
	// Traverse operation
void traverse() {
    if (isUnderflow()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Traversing stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack as an ADT ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Traverse\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
	    if (s.isOverflow()) {
        cout << " Stack Overflow! Cannot push." << endl;
    } else {
        cout << "Enter value to push: ";
        cin >> value;
        s.push(value);
    }
    break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.traverse();
            break;
        case 5:
            cout << " Exiting program..." << endl;
            break;
        default:
            cout << " Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

