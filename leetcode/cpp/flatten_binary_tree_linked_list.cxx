//
//  Flatten Binary Tree to Linked List
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//  
//  Given a binary tree, flatten it so that all nodes appear in order
//  in one right expanding branch.
//
//  Eg.      1                1
//         /   \               \
//       2       5    =====>    2
//      / \       \              \
//     3   4       6              3
//                                 \
//                                  4
//                                   \
//                                    5
//  Joel Rorseth                       \
//  Created on June 23, 2017            6
//

#include <iostream>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Solution 1 (Recursive)
void flatten(TreeNode * root) {

    // Post order traversal through the tree
    // Remember that in sorted binary tree, post order traverses decreasing
    if(!root) return;
    flatten(root->right);
    flatten(root->left);

    // Previous node was larger, thus assign it as right node
    root->right = previous;
    root->left = NULL;

    // Set previous to this current node, so that this node can be
    // linked as the next node's right
    previous = root;
}



// Solution 2 (Iterative)
void flatten_iterative(TreeNode* root) {

    TreeNode * current = root;

    while (current) {

        // If there exists a left branch (that we obviously most move)...
        if (current->left) {

            TreeNode * pre = current->left;

            // Find the rightmost leaf node of this left branch 
            // This will be the node that comes before the first in current->left branch
            while (pre->right)
                pre = pre->right;

            // Realign these in order, using only right branch
            pre->right = current->right;

            // Move this new branch formed into current nodes right branch
            // Then null out the left branch to move on...
            current->right = current->left;
            current->left = NULL;
        }

        // Move onto next node in right branch path
        current = current->right;
    }
}
