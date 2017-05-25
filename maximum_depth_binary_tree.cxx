//
//  Maximum Depth of Binary Tree
//  https://leetcode.com/problems/maximum-depth-of-binary-tree/
//  
//  Given a Binary Tree (definition given), determine the maximum
//  depth (distance from root to furthest node from root).
//
//  Joel Rorseth
//  Created on May 25, 2017
//

#include <iostream>
#include <algorithm>

//Definition for a binary tree node (given)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution
int max_depth(TreeNode * root) {
    return (root == NULL) ? 0 : 1 + std::max( max_depth(root->left), max_depth(root->right));
}

// Demonstration
int main() {

    TreeNode * head = new TreeNode(1);
    TreeNode * l = new TreeNode(2);
    TreeNode * ll = new TreeNode(3);
    TreeNode * lll = new TreeNode(4);
    TreeNode * r = new TreeNode(5);
    TreeNode * rl = new TreeNode(6);

    ll->left = lll;
    r->left = rl;
    l->left = ll;
    head->left = l;
    head->right = r;

    std::cout << "Given linked list with max depth = 4, max_depth returned "
        << max_depth(head) << std::endl;
}
