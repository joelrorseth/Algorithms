//
// Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
//
// Given a binary tree, determine the path with the maximum sum.
// The path does not need to go through the root node, and must
// contain least one node. The path can traverse down any combination
// of branches.
//

#include <iostream>
#include <algorithm>
#include <climits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



int dfs(TreeNode * root, int & maxpath) {
    
    if (!root) return 0;
    
    // Traverse left and right subtrees and find maxpath sums
    int left = std::max( 0, dfs(root->left, maxpath) );
    int right = std::max( 0, dfs(root->right, maxpath) );
    
    maxpath = std::max( maxpath, left + right + root->val );
    
    return root->val + std::max(left, right);
}


int maxPathSum(TreeNode* root) {
    
    // Perform DFS, pass result by reference for easy modification
    int maxpath = INT_MIN;
    dfs(root, maxpath);
    return maxpath;
}


int main() {}
