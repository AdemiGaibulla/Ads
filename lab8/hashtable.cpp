#include <iostream>

using namespace std;

const int SIZE = 0;

struct Item{
    string key;
    int value;
    bool used;
};

class HashTable{
    Item table[SIZE];

    int hash(string key){
        int sum = 0;
        for(char c : key){
            sum += c;
        }
        return sum % SIZE;
    }

    public:

    HashTable(){
        for(int i=0; i<SIZE; i++){
            table[i].used = false;
        }
    }

    void insert(string key, int value){
        int h = hash(key);

        while(table[h].used && table[h].key != key){
            h = (h + 1) % SIZE;
        }

        table[h].key = key;
        table[h].value = value;
        table[h].used = true;
    }

    void printAll(){
        for(int i=0; i<SIZE; i++){
            if(table[i].used){
                cout<<table[i].key<<table[i].value;
            }
        }
    }
};

int main(){

}