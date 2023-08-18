#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    int table[TABLE_SIZE];

public:
    HashTable() {
        // Initialize all elements of the table to -1 (indicating an empty slot)
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);

        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE; // Probe to the next index
        }

        table[index] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);

        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % TABLE_SIZE; // Probe to the next index
        }

        return false;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            if (table[i] != -1) {
                cout << table[i];
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

