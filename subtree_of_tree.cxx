//
// Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/
//
// Given two trees 's' and 't', determine if 't' is a subtree of 's'.
// To be a subtree, 't' must have the exact same structure, node values
// as a subtree in 's', and must consist of all of a node in s's decendants.
//

#include <iostream>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};


bool equals(TreeNode * s, TreeNode * t) {
    
    if (!s && !t) return true;
    if (!s || !t) return false;
    
    // Check if current node is equal, then recursively check if left=left and right=right
    return s->val == t->val && equals(s->left, t->left) && equals(s->right, t->right);
}


bool isSubtree(TreeNode * s, TreeNode * t) {
    // Recursively check each subtree for equality to 't'
    return s && (equals(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
}


int main() {}
