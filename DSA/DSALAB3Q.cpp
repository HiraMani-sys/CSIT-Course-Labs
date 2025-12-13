#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#define MAX 100

class Stack {
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
        } else {
            arr[++top] = x;
        }
    }

    char pop() {
        if (isempty()) {
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

string infixToPostfix(const string& infix) {
    Stack op_stack;
    string postfix = "";

for (size_t i = 0; i < infix.length(); ++i) {
    char token = infix[i];
	        if (isalnum(token)) {
            postfix += token;
        } else if (token == '(') {
            op_stack.push(token);
        } else if (token == ')') {
            while (!op_stack.isempty() && op_stack.peek() != '(') {
                postfix += op_stack.pop();
            }
            if (!op_stack.isempty() && op_stack.peek() == '(') {
                op_stack.pop();
            }
        } else {
            while (!op_stack.isempty() && op_stack.peek() != '(') {
                int incoming_prec = precedence(token);
                int stack_prec = precedence(op_stack.peek());

                if (stack_prec > incoming_prec) {
                    postfix += op_stack.pop();
                } else if (stack_prec == incoming_prec) {
                    if (token != '^') { 
                        postfix += op_stack.pop();
                    } else {
                        break; 
                    }
                } else {
                    break;
                }
            }
            op_stack.push(token);
        }
    }

    while (!op_stack.isempty()) {
        postfix += op_stack.pop();
    }

    return postfix;
}

int main() {
    string test1 = "a*b+c/d";
    string test2 = "a+b^c^d-e";
    string test3 = "(a+b)*c^d";

    cout << "--- Infix to Postfix Conversion ---" << endl;
    cout << "Test 1 (Infix): " << test1 << endl;
    cout << "Postfix: " << infixToPostfix(test1) << " (Expected: ab*cd/+) " << endl;
    
    cout << "-----------------------------------" << endl;
    cout << "Test 2 (Infix): " << test2 << endl;
    cout << "Postfix: " << infixToPostfix(test2) << " (Expected: abc^d^-e) " << endl;
    
    cout << "-----------------------------------" << endl;
    cout << "Test 3 (Infix): " << test3 << endl;
    cout << "Postfix: " << infixToPostfix(test3) << " (Expected: ab+c d^) " << endl;
    cout << "-----------------------------------" << endl;
    
    return 0;
}
