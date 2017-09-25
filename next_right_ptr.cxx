//
// Populating Next Right Pointers in Each Node
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
//
// Given a binary tree, populate each node's 'next' pointer. In the definition
// provided, the next pointer points to the node to the right of itself on the
// same level.
//
//
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \  / \
//    4->5->6->7 -> NULL
//

#include <iostream>

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


// Solution
void connect(TreeLinkNode *root) {
    
    if (!root) return;
    
    // Left child node's next should point to the right child node
    if (root->left)
        root->left->next = root->right;
    
    // Right child node's next should point to root's next's left child
    if (root->right)
        root->right->next = (root->next ? root->next->left : NULL);
    
    // Recurse from the left (DFS)
    connect(root->left);
    connect(root->right);
}


int main() {}
