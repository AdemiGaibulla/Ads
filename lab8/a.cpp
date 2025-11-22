#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;
const long long PRIME = 11;
const int SIZE = 100007;

struct Item {
    string key;
    bool used;
};

class HashTable {
    Item table[SIZE];

    int hashFunc(const string &key) {
        unsigned long long sum = 0;
        for (char c : key)
            sum = (sum * 131 + c) % SIZE;
        return sum % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i].used = false;
    }

    void insert(const string &key) {
        int h = hashFunc(key);
        while (table[h].used && table[h].key != key)
            h = (h + 1) % SIZE;
        table[h].key = key;
        table[h].used = true;
    }

    bool exists(const string &key) {
        int h = hashFunc(key);
        int start = h;
        while (table[h].used) {
            if (table[h].key == key)
                return true;
            h = (h + 1) % SIZE;
            if (h == start) break;
        }
        return false;
    }
};

long long Hash(const string &s) {
    long long hash = 0, power = 1;
    for (char c : s) {
        hash = (hash + (c - 47) * power) % MOD;
        power = (power * PRIME) % MOD;
    }
    return hash;
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n*2);
    HashTable table;

    for (int i=0; i<n*2; i++) {
        cin >> v[i];
        table.insert(v[i]);
    }

    int printed = 0;
    for (int i=0; i<n*2 && printed<n; i++) {
        string s = v[i];
        string hStr = to_string(Hash(s));
        if (table.exists(hStr)) {
            cout << "Hash of string \"" << s << "\" is " << hStr << endl;
            printed++;
        }
    }
}