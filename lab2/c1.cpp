#include <iostream>

using namespace std;

struct Node{
    string val;
    Node* next;
    Node(string x) : val(x), next(nullptr){}
};

int main (){
    int n, k, cnt= 0;
    cin>>n>>k;
    string s;
    Node* head = nullptr;
    Node* temp = head;
 
    for (int i=0; i<n ;i++){
        cin>>s;
        Node* node = new Node(s);
        if(head==nullptr) head = temp = node;
        else{
            temp->next= node;
            temp= node;
        }
    }
 
    Node* current =head;
    while(current !=nullptr){
        if (cnt>=k){
            cout<<current->val<< ' ';
        }
        current=current->next;
        cnt++;
    }
    cnt=0;
    current =head;

    while(cnt<k){
        cout<<current->val<< ' ';
        current=current->next;
        cnt++;
    }
}