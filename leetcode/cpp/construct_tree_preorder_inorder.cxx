//
//  Construct Binary Tree from Preorder and Inorder Traversal
//  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//
//  Given the preorder and inorder traversal of some binary tree, re-construct
//  this tree.
//
//  Joel Rorseth
//  Created on June 30, 2017
//

#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



// Solution (recursive)
TreeNode * build_tree_recursive
(int pre_start, int in_start, int in_end, std::vector<int> & preorder, std::vector<int> & inorder) {

    int in_root_index = 0;

    if (pre_start > preorder.size() - 1 || in_start > in_end)
        return nullptr;

    // Obtain current root (always first in a preorder traversal)
    TreeNode * root = new TreeNode(preorder[pre_start]);


    // Proceed to find position of this root in the inorder traversal
    // In inorder, all nodes to left of root (located at center) are in left subtree

    for (int i = in_start; i <= in_end; ++i)
        if (inorder[i] == root->val)
            in_root_index = i;


    // Recursively create the left and right subtrees
    // Left: [in_start, in_root_index), Right: (in_root_index, in_end]

    root->left = build_tree_recursive(pre_start + 1, in_start, in_root_index - 1, preorder, inorder);
    root->right = build_tree_recursive(pre_start + in_root_index - in_start + 1, in_root_index + 1, in_end, preorder, inorder);
    return root;
}


TreeNode* build_tree(std::vector<int> & preorder, std::vector<int>& inorder) {
    return build_tree_recursive(0, 0, inorder.size() - 1, preorder, inorder);
}


// No demonstration
int main(){}