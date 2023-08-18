#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int front;
    int rear;
    int arr[MAX_SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(3);
   
    q.print();  // Output: 1 2 3

q.dequeue();
    q.dequeue();
	q.dequeue();
	q.enqueue(3);
    q.print();
    cout << q.peek() << endl;  // Output: 2

    return 0;
}

