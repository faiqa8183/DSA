#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to check precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return -1;
    }
}

// Function to convert infix expression to postfix
string infix_to_postfix(string expression) {
    stack<char> stack;
    string result = "";
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        } else if (is_operator(c)) {
            while (!stack.empty() && is_operator(stack.top()) && precedence(stack.top()) >= precedence(c)) {
                result += stack.top();
                stack.pop();
            }
            stack.push(c);
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                result += stack.top();
                stack.pop();
            }
            stack.pop(); // Discard the '('
        }
    }
    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
    return result;
}

int main() {
    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression);
    string postfix = infix_to_postfix(expression);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}

