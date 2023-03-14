//
// Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
//
// Given a binary tree (no ordering property), find the lowest common
// ancestor of two given nodes in the tree.
//

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// DFS Solution
TreeNode * lowest_common_ancestor(TreeNode * root, TreeNode * p, TreeNode * q) {

    if (!root || root==p || root==q) return root;

    // Recursively check left and right subtrees
    auto left = lowest_common_ancestor(root->left, p, q);
    auto right = lowest_common_ancestor(root->right, p, q);

    // If left and right were defined, return root
    return !left ? right : (!right ? left : root);
}


int main() {}
