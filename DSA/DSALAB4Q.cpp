#include<iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
#define MAX 100
class Stack {
	public:
    char arr[MAX];
    int top;
public:
    Stack() {
        top = -1; 
    }

    bool isempty() {
        return top == -1;
    }
    
    bool isfull() {
        return top == MAX - 1;
    }

    void push(char x) {
        if (isfull()) {
        	        cout << "Stack overflow! Cannot push " << x << endl;
        } else {
            arr[++top] = x;
        }
    }

    char pop() {
        if (isempty()) {        
		cout << "Stack underflow! Cannot pop." << endl;
            return '\0'; 
        } else {
            return arr[top--];
        }
    }

    char peek() {
        if (isempty()) {
            return '\0'; 
        }
        return arr[top];
    }
};

int precedence(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

// Helpers to print stack contents
string printStack(char arr[], int top) {
    string s = "";
    for (int i = 0; i <= top; i++) {
        s += arr[i];
    }
    return s;
}

string printIntStack(int arr[], int top) {
    string s = "";
    for (int i = 0; i <= top; i++) {
        s += (char)(arr[i] + '0');
        s += " ";
    }
    return s;
}

// Infix to Postfix with trace
string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";
    cout << "\n--- Infix to Postfix Table ---\n";
    cout << "Scanned\t|Postfix\t|OperatorStack\n";

    for (int i = 0; i < (int)infix.size(); i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.isempty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop();
        } else {
            while (!st.isempty() && precedence(st.peek()) >= precedence(ch)) {
                postfix += st.pop();
            }
            st.push(ch);
        }
        cout << ch << "\t" << postfix << "\t\t " << printStack(st.arr, st.top) << endl;
    }
    while (!st.isempty()) {
        postfix += st.pop();
        cout << " \t" << postfix << "\t" << printStack(st.arr, st.top) << endl;
    }
    return postfix;
}

// Infix to Prefix (reverse trick)
string infixToPrefix(string infix) {
    string rev = "";
    for (int i = (int)infix.size() - 1; i >= 0; i--) {
        if (infix[i] == '(') rev += ')';
        else if (infix[i] == ')') rev += '(';
        else rev += infix[i];
    }
    string postfix = infixToPostfix(rev);
    string prefix = "";
    for (int i = (int)postfix.size() - 1; i >= 0; i--) {
        prefix += postfix[i];
    }
    return prefix;
}

// Postfix Evaluation with table
int evalPostfix(string postfix) {
    int stack[MAX], top = -1;
    cout << "\nScanned | Result | Operand Stack\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < (int)postfix.size(); i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            stack[++top] = ch - '0';
            cout << ch << "        push " << (ch - '0') << "   " << printIntStack(stack, top) << endl;
        } else {
            int b = stack[top--];
            int a = stack[top--];
            int res = 0;
            switch (ch) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': res = (int)pow(a, b); break;
            }
            stack[++top] = res;
            cout << ch << "        " << a << ch << b << "=" << res << "  " << printIntStack(stack, top) << endl;
        }
    }
    return stack[top];
}

// Prefix Evaluation with table
int evalPrefix(string prefix) {
    int stack[MAX], top = -1;
    cout << "\nScanned | Result | Operand Stack\n";
    cout << "---------------------------------\n";
    for (int i = (int)prefix.size() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isdigit(ch)) {
            stack[++top] = ch - '0';
            cout << ch << "        push " << (ch - '0') << "   " << printIntStack(stack, top) << endl;
        } else {
            int a = stack[top--];
            int b = stack[top--];
            int res = 0;
            switch (ch) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': res = (int)pow(a, b); break;
            }
            stack[++top] = res;
            cout << ch << "        " << a << ch << b << "=" << res << "  " << printIntStack(stack, top) << endl;
        }
    }
    return stack[top];
}
int main() {
    int choice;
    string infix, postfix, prefix;

	cout << "Hira Mani Rai" << endl << endl;
    cout << "Input the following number for operation." << endl;
    cout << "1. Infix to Postfix" << endl;
    cout << "2. Infix to Prefix" << endl;
    cout << "3. Evaluate Postfix" << endl;
    cout << "4. Evaluate Prefix" << endl;
    cout << "5. Exit" << endl;

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter infix expression: ";
                cin >> infix;
                postfix = infixToPostfix(infix);
                cout << "\nPostfix: " << postfix << endl;
                break;
            }
            case 2: {
                cout << "Enter infix expression: ";
                cin >> infix;
                prefix = infixToPrefix(infix);
                cout << "\nPrefix: " << prefix << endl;
                break;
            }
            case 3: {
                cout << "Enter postfix expression: ";
                cin >> postfix;
                cout << "Postfix: " << postfix << endl;
                cout << "\nEvaluation Result: " << evalPostfix(postfix) << endl;
                break;
            }
            case 4: {
                cout << "Enter prefix expression: ";
                cin >> prefix;
                cout << "Prefix: " << prefix << endl;
                cout << "\nEvaluation Result: " << evalPrefix(prefix) << endl;
                break;
            }
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
            	return 1;
        }
    } while (choice != 5);

    return 0;
}

