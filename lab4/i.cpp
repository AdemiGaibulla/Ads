#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(NULL), right(NULL) {}
};

int cnt[1000] = {0};
Node* insertNode(Node* root, int x){
    if(root==NULL) return new Node(x);
    if(x<root->val) root->left = insertNode(root->left,x);
    if(x>root->val) root->right = insertNode(root->right, x);
    return root;
}
Node* findmin(Node* root){
    while(root->left!=NULL) root =  root->left;
    return root;
}
Node* deleteNode(Node* root, int x){
    if(root==NULL) return NULL;

    if(x<root->val) root->left = deleteNode(root->left, x);
    else if(x>root->val) root->right =  deleteNode(root->right, x);
    else{
        if(root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findmin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main(){
    int n;
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        string command;
        int num;
        cin>>command>>num;

        if(command=="insert") {
            if(cnt[num]==0) root = insertNode(root,num);
            cnt[num]++;
        }
        if(command=="delete"){
            if(cnt[num]>1) cnt[num]--;
            else if(cnt[num]==1) {
                root = deleteNode(root, num); 
                cnt[num]=0;
            }
        }
        if(command=="cnt") cout<<cnt[num]<<endl;
    }
}