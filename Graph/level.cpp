#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to perform level order traversal
void levelorder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " "; // Print current node

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << "\n"; // New line after printing all levels
}

// Function to build a binary tree from a given array
Node* build(vector<int>& arr, int& idx) {
    if (idx >= arr.size() || arr[idx] == -1) {
        idx++;
        return nullptr;
    }
    Node* root = new Node(arr[idx++]);
    root->left = build(arr, idx);
    root->right = build(arr, idx);
    return root;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int idx = 0;
        Node* root = build(arr, idx);
        levelorder(root); // Print level order traversal
    }
    return 0;
}
