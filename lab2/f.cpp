#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int v){
        val = v;
        next = nullptr;
    }
};
class LinkedList{
    public:
    Node* head;

    LinkedList(){
        head = nullptr;
    }
    void append(int v){
        Node* newNode = new Node(v);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout << endl;
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
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        ll.append(number);
    }
    int k,index;
    cin>>k>>index;
    ll.insertAt(index, k);
    ll.print();
}