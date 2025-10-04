#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if(p==0){
        node->next=head;
        head = node;
        return node;
    }
    Node* temp = head;
    int index = 0;
    while(temp!=nullptr && index < p-1){
        temp = temp->next;
        index++;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
};
 
Node* remove(Node* head, int p){
    if(p==0){
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    Node* temp = head;
    int index = 0;
    while(temp->next!=nullptr && index < p-1){
        temp=temp->next;
        index++;
    }
    if(temp->next!=nullptr){
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    return head;
};
 
Node* replace(Node* head, int p1, int p2) {
    if (!head || !head->next || p1 == p2) return head;

    Node* prev1 = nullptr;
    Node* node1 = head;
    for (int i = 0; i < p1; i++) {
        prev1 = node1;
        node1 = node1->next;
    }

    if (prev1) prev1->next = node1->next;
    else head = node1->next;

    if (p2 == 0) {
        node1->next = head;
        head = node1;
        return head;
    }

    Node* prev2 = head;
    for (int i = 0; i < p2 - 1; i++) {
        prev2 = prev2->next;
    }

    node1->next = prev2->next;
    prev2->next = node1;

    return head;
}

Node* reverse(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
};
 
void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
};
 
Node* cyclic_left(Node* head, int x) {
    if (!head || !head->next) return head;

    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    x %= len;
    if (x == 0) return head;

    Node* newTail = head;
    for (int i = 1; i < x; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    if (!head || !head->next) return head;

    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    x %= len;
    if (x == 0) return head;

    Node* newTail = head;
    for (int i = 1; i < len - x; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}

 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}