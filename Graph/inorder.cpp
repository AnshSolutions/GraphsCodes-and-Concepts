#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to perform inorder traversal and store result in a vector
void inorder(Node* root, vector<int>& ans) {
    if (root == nullptr) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

// Function to return the inorder traversal of a binary tree
vector<int> inOrder(Node* root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

// Function to build a binary tree from input vector using level-order traversal
Node* buildTree(vector<int>& arr, int& index) {
    if (index >= arr.size() || arr[index] == -1) { // -1 represents NULL node
        index++;
        return nullptr;
    }
    Node* root = new Node(arr[index++]);
    root->left = buildTree(arr, index);
    root->right = buildTree(arr, index);
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Number of nodes in the binary tree
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        int index = 0;
        Node* root = buildTree(arr, index); // Construct the binary tree
        
        vector<int> result = inOrder(root); // Get inorder traversal
        for (int val : result) cout << val << " "; // Print inorder traversal
        cout << "\n";
    }
    return 0;
}