#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = NULL;
    }
    
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }
    
    bool isEmpty() {
        return top == NULL;
    }
    
    void display() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.display(); // Output: 15 10 5
    s.pop();
    s.display(); // Output: 10 5
    cout << "Top element is " << s.peek() << endl; // Output: Top element is 10
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Output: Is stack empty? No
    return 0;
}

