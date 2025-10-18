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
Node* find(Node* root, int x){
    while(root!=NULL){
        if(root->val==x) return root;
        else if(x < root->val) root= root->left;
        else root = root->right;
    }
    return NULL;
}

void preorder(Node* root){
    if(root==NULL) return;
    cout<< root->val;
    preorder(root->left);
    preorder(root->right);
}
int size(Node* root){
    if(root==NULL) return 0;
    return 1 + size(root->left) + size(root->right);
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

    int x;
    cin>>x;
    Node* subroot = find(root,x);
    if(subroot!=NULL){
        int sizeoftree = size(subroot);
        cout<<sizeoftree;
    }
}