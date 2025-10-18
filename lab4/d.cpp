#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int x) {
    if (root == NULL) return new Node(x);
    if (x < root->val) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

int main() {
    int n; 
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        root = insert(root, x);
    }

    vector<int> levelSums;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        int sum = 0;
        for (int i = 0; i < sz; i++) {
            Node* cur = q.front(); q.pop();
            sum += cur->val;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        levelSums.push_back(sum);
    }

    cout << levelSums.size() << endl;
    for (int s : levelSums) cout << s << " ";
    cout << endl;
}
