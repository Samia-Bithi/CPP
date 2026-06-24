#include <iostream>
#include <list>
using namespace std;

class HashTable {
    int bucket; // number of buckets
    list<pair<int, string>> *table; // array of linked lists

public:
    HashTable(int b) {
        bucket = b;
        table = new list<pair<int, string>>[bucket];
    }

    int hashFunction(int key) {
        return key % bucket;
    }

    void insert(int key, string value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    void remove(int key) {
        int index = hashFunction(key);
        auto &chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                chain.erase(it);
                break;
            }
        }
    }

    string search(int key) {
        int index = hashFunction(key);
        auto &chain = table[index];
        for (auto &p : chain) {
            if (p.first == key)
                return p.second;
        }
        return "Not Found";
    }

    void display() {
        for (int i = 0; i < bucket; i++) {
            cout << i << ": ";
            for (auto &p : table[i])
                cout << "(" << p.first << ", " << p.second << ") ";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7); // table with 7 buckets
    ht.insert(10, "Alice");
    ht.insert(15, "Bob");
    ht.insert(21, "Charlie");
    ht.insert(31, "Dave");

    cout << "\nHash Table Contents:\n" << endl;
    ht.display();

    cout << "\nSearch key 25: " << ht.search(25) << endl;
    cout << "Search key 31: " << ht.search(31) << endl;

    ht.remove(15);

    cout << "\nAfter deletion:\n" << endl;
    ht.display();

    return 0;
}
