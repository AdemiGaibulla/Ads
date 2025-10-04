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
};

int main(){
    int n;
    cin>>n;
    LinkedList ll;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        ll.append(number);
    }
    Node* temp = ll.head;
    int i=0;
    while(temp != nullptr){
        if(i%2==0) cout<<temp->val<<" ";
        temp = temp->next;
        i++;
    }
}