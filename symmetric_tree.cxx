//
// Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/
//
// Determine if a binary tree is symmetric (about its center)
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool isSymmetric(TreeNode * left, TreeNode * right) {
    
    // To terminate with True, both left and right symmetric pairs should be NULL
    if (!left || !right)
    return left == right;
    
    // If symmetric pairs are not same, tree is not symmetric
    if (left->val != right->val)
    return false;
    
    // Match up left and right children from both left and right nodes to check for symmetry
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}


bool isSymmetric(TreeNode * root) {
    // Skip ahead to second layer and compare each left/right node's children
    return root == NULL || isSymmetric(root->left, root->right);
}


int main() {}
