#include<bits/stdc++.h>
using namespace std;
 int maxsum;
     int solve(Node *root){
        if (root == nullptr) return 0;

        // Compute max path sum from left and right subtrees
        int l = max(0, solve(root->left));  // Ignore negative paths
        int r = max(0, solve(root->right)); // Ignore negative paths
        
        // Compute max sum including both left and right
        int nodeMax = root->data + l + r;

        // Update global max sum
        maxsum = max(maxsum, nodeMax);

        // Return max path sum extending downward
        return root->data + max(l, r);
     }
    int findMaxSum(Node *root) {
     maxsum=INT_MIN;
       solve(root);
       return maxsum;
    }