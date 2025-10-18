#include <iostream>
#include <queue>

using namespace std;

struct Node {
    long long val;
    Node* left;
    Node* right;
    Node(long long v) : val(v), left(NULL), right(NULL) {}
};

void insert(Node* root, long long x, long long y, long long z) {
    if (!root) return;
    if (root->val == x) {
        if (z == 0) root->left = new Node(y);
        else root->right = new Node(y);
    } else {
        insert(root->left, x, y, z);
        insert(root->right, x, y, z);
    }
}

long long maxwidth(Node* root) {
    if (!root) return 0;

    queue<Node*> q;
    q.push(root);
    long long maxWidth = 0;

    while (!q.empty()) {
        long long levelSize = q.size();
        if (levelSize > maxWidth)
            maxWidth = levelSize;

        for (long long i = 0; i < levelSize; i++) {
            Node* cur = q.front();
            q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return maxWidth;
}

int main() {
    long long n;
    cin >> n;
    Node* root = NULL;

    for (int i = 0; i < n - 1; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        if (!root) root = new Node(x);
        insert(root, x, y, z);
    }

    cout << maxwidth(root);
}
