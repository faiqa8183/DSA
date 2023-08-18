#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }
    
    int peek() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }
    
    bool isEmpty() {
        return front == NULL;
    }
    
    void display() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.display(); // Output: 5 10 15
    q.dequeue();
    q.display(); // Output: 10 15
    cout << "Front element is " << q.peek() << endl; // Output: Front element is 10
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Output: Is queue empty? No
    return 0;
}

