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
    else if(x > root->val) root->right = insert(root->right,x);
    return root;
}

int sum=0;
void reverseinorder(Node* root){
    if(root!=NULL){
        reverseinorder(root->right);
        sum+=root->val;
        cout<<sum<<" ";
        reverseinorder(root->left);
    }
}
int main(){
    int n;
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        root = insert(root,number);
    }
    reverseinorder(root);
}