#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;
    Node* tail;

    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtTail(int data) {
        Node* new_node = new Node(data);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
            new_node->next = head;
        }
        else {
            tail->next = new_node;
            tail = new_node;
            tail->next = head;
        }
    }

    void insertAtHead(int data) {
        Node* new_node = new Node(data);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
            new_node->next = head;
        }
        else {
            new_node->next = head;
            head = new_node;
            tail->next = head;
        }
    }

    void deleteHead() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        }
        else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void deleteTail() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        }
        else if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            Node* temp = tail;
            tail = current;
            tail->next = head;
            delete temp;
        }
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        }
        else {
            Node* current = head;
            cout << "List: ";
            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);
            cout << endl;
        }
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);
    cll.insertAtHead(0);
    cll.print();
    cll.deleteHead();
    cll.print();
    cll.deleteTail();
    cll.print();
    return 0;
}

