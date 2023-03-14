//
//  Invert Binary Tree
//  https://leetcode.com/problems/invert-binary-tree/
//  
//  Invert a binary tree (horizontally).
//
//       5                  5
//    3     4     ==>     4    3
//  1   2  8  9         9  8  2  1     
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
    TreeNode(int x, TreeNode * l, TreeNode * r) : val(x), left(l), right(r) {}
};

// Solution (Recursive)
TreeNode* invert_tree(TreeNode * root) {

    if (root) {
        TreeNode * left = invert_tree(root->left);
        TreeNode * right = invert_tree(root->right);
        std::swap(root->left, root->right);
    }

    return root;
}



// Binary Tree Flat Print
void print_tree_inorder(TreeNode * root) {

    if (!root) return;

    print_tree_inorder(root->left);
    std::cout << root->val << ',';
    print_tree_inorder(root->right);
}

// Demonstration
int main() {

    TreeNode * ll = new TreeNode(1);
    TreeNode * lr = new TreeNode(2);
    TreeNode * rl = new TreeNode(8);
    TreeNode * rr = new TreeNode(9);
    TreeNode * l = new TreeNode(3, ll, lr);
    TreeNode * r = new TreeNode(4, rl, rr);
    TreeNode * tree = new TreeNode(5, l, r);

    std::cout << "Binary Tree (Inorder): {";
    print_tree_inorder(tree);

    std::cout << "}\nBinary Tree after invert: {";
    print_tree_inorder(invert_tree(tree));
    std::cout << '}' << std::endl;
}
