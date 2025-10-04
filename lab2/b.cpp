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

int main(){
    int n,k;
    cin>>n>>k;
    string words;
    cin>>words;
    Node* head = nullptr;
    Node* prev1 = nullptr;
    Node* node1 = head;
    for (int i = 0; i < (n-k); i++) {
        prev1 = node1;
        node1 = node1->next;
    }

    if (prev1) prev1->next = node1->next;
    else head = node1->next;

}