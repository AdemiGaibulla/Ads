#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int v) : val(v), next(NULL) {};
};

class LinkedList{
    public:
    Node* head;

    LinkedList() : head(NULL) {};

    void append(int x){
        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp -> next = newNode;
    }

    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val;
            temp = temp->next;
        }
    }

    void remove(int x){
        if(head == NULL) return;
        if(head->val == x){
            Node* toDelete = head;
            head = head -> next;
            delete toDelete;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL && temp->next->val != x){
            temp = temp->next;
        }
        if(temp->next != NULL){
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
};