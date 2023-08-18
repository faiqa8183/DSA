#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
    data = value;
    next = nullptr;
}

};

class HashTable {
private:
    Node* table[TABLE_SIZE];

public:
    HashTable() {
        // Initialize all elements of the table with nullptr
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);

        Node* newNode = new Node(key);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool search(int key) {
        int index = hashFunction(key);

        Node* current = table[index];
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(6);
    hashTable.insert(16);

    hashTable.display();

    cout << "Search 5: " << (hashTable.search(5) ? "Found" : "Not found") << endl;
    cout << "Search 10: " << (hashTable.search(10) ? "Found" : "Not found") << endl;

    return 0;
}

