//
// Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/
//
// Given a binary tree, find the leftmost value in the LAST ROW of the tree.
//

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Solution
void dfs(TreeNode * root, int & leftmost_depth, int & leftmost, int cur_depth) {
    
    if (!root) return;
    
    // DFS, passign current depth and current leftmost
    dfs(root->left, leftmost_depth, leftmost, cur_depth + 1);
    dfs(root->right, leftmost_depth, leftmost, cur_depth + 1);
    
    // If this row is the lowest yet, record this value as new left/bottom most
    // We can assume this is leftmost for this row due to left to right nature of DFS!!
    
    if (cur_depth > leftmost_depth) {
        leftmost_depth = cur_depth;
        leftmost = root->val;
    }
}

// Solution entry point
int findBottomLeftValue(TreeNode* root) {
    int depth = 0;
    int leftmost = root->val;
    
    dfs(root, depth, leftmost, 0);
    return leftmost;
}

int main() {}
