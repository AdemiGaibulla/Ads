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
    if( x < root->val) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}
int main(){
    int n,m;
    cin>>n>>m;
    Node* root = NULL;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        root = insert(root, number);
    }

    for(int i=0;i<m;i++){
        string d;
        cin>>d;
        Node* cur = root;
        int a = 1;
        for(int j=0; j<d.length(); j++){
            if(d[j]=='L') {
                if(cur->left == NULL) {
                    a = 0;
                    break;}
                cur = cur->left;
            }
            else {
                if(cur->right == NULL) {
                    a = 0;
                    break;
                }
                cur = cur->right;
            }
        }
        if(a==0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}