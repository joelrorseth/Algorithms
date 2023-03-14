//
//  Balanced Binary Tree
//  https://leetcode.com/problems/balanced-binary-tree
//
//  Determine if a binary tree is unbalanced. A tree is considered
//  unbalanced if at any depth, the difference in height of the left 
//  and right subtrees is greater than one
//
//  Joel Rorseth
//  Created on July 17, 2017
//

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Solution (Depth First Search)
int dfs_height (TreeNode * root) {
    if (root == NULL) return 0;

    // 2. If left or right subtree height is set to unbalanced, then it
    // is therefore still unbalanced at this level and above

    int leftHeight = dfs_height(root -> left);
    if (leftHeight == -1) return -1;

    int rightHeight = dfs_height(root -> right);
    if (rightHeight == -1) return -1;

    // 1. If left and right subtree heights are 'unbalanced', return -1
    // -1 signifies unbalanced (subtree heights differ by a factor > 1)

    if (abs(leftHeight - rightHeight) > 1)  return -1;
    return std::max(leftHeight, rightHeight) + 1;
}

bool is_balanced(TreeNode * root) {

    // Check against -1 (unbalanced)
    return dfs_height(root) != -1;
}

int main(){}
