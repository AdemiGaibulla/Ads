#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = nullptr;
    }
};
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void append(int v) {
        Node* newNode = new Node(v);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->val;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void remove(int v) {
        if (head == nullptr) return;
        if (head->val == v) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->val != v) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    Node* getAt(int index) {
    Node* temp = head;
    int i = 0;
    while (temp != nullptr && i < index) {
        temp = temp->next;
        i++;
    }
    return temp;
    }

    void insertAt(int i, int v){
        Node* newNode = new Node(v);
        if (i == 0) {
        newNode->next = head;
        head = newNode;
        return; }

        Node* temp=head;
        int index = 0;
        while(temp!= nullptr && index < i-1){
            temp = temp->next;
            index++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
};

int main(){
    int n;
    cin>>n;
    LinkedList ll;
    
    
}