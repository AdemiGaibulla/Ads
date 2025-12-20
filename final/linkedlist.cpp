#include <iostream>
#include <vector>

using namespace std;

struct Node{
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
            temp = temp->next;
        }
        temp -> next = newNode;
    }

    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->val;
            temp = temp->next;
        }
    }

    void insertAt(int i, int v){
        Node* newNode = new Node(v);
        if(i==0){
            head = newNode;
            return;
        }

        Node* temp = head;
        int index = 0;
        while(temp != nullptr && index < i-1){
            temp = temp->next;
            index++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void remove(int v){
        if(head == nullptr) return;
        if(head->val == v){
            Node * toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr && temp->next->val != v){
            temp = temp->next;
        }
        if(temp->next != nullptr){
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
};

