#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int x){
    if(root==NULL) return new Node(x);
    if(x < root->val) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}
void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->val <<" ";
    preorder(root->left);
    preorder(root->right);
}
Node* find(Node* root, int x){
    while(root!=NULL){
        if(root->val == x) return root;
        else if(x < root->val) root = root->left;
        else root = root->right;
    }
    return NULL;
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        root = insert(root, number);
    }
    int k;
    cin>>k;
    Node* subroot = find(root, k);
    if(subroot) preorder(subroot);
}