#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node* insert (Node* root, int x){
    if(root==NULL) return new Node(x);
    if(x < root->val) root->left = insert(root->left, x);
    else if (x > root->val) root->right = insert(root->right, x);
    return root;
}

int d = 0;

int max_distance(Node* root){
    if(root==NULL) return 0;
    int left_s = max_distance(root->left);
    int right_s = max_distance(root->right);
    d = max(d, left_s + right_s);
    return 1 + max(left_s, right_s);
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        root =  insert(root, number);
    }
    max_distance(root);
    cout<<d+1;
}