#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int v): val(v), left(NULL), right(NULL) {}
};
Node* insert(Node* root, int x){
    if(root==NULL) return new Node(x);
    if( x < root->val) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

int triangle_search(Node* root){
    if (root == NULL) return 0;
    int cnt = 0;
    if(root->left && root->right) cnt = 1;
    return cnt + triangle_search(root->left) + triangle_search(root->right);
}
int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        root = insert(root,number);
    }
    cout<<triangle_search(root);
}