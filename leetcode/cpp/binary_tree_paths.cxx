//
//  Binary Tree Paths
//  https://leetcode.com/problems/binary-tree-paths/
//  
//  Given a binary tree, return a list of all possible paths from the
//  root to each leaf. 
//
//  Eg. [1,2,3,null,5]  ==>  ["1->2->5", "1->3"]
//
//  Joel Rorseth
//  Created on June 22, 2017
//

#include <iostream>
#include <vector>
#include <string>

// Note: This is a really good basic demonstration of a depth first 
// search algorithm


// Tree definition (given)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



// DFS Solution
void binary_tree_paths(std::vector<std::string> & result, TreeNode * root, std::string t) {

    // Base case: node is null
    // Now the path string is finished, append to resulting array
    if (!root->left && !root->right) {
        result.push_back(t);
        return;
    }

    // Traverse left, then right subtrees recursively
    // This makes it a depth first search DFS
    if (root->left)
        binary_tree_paths(result, root->left, t + "->" + std::to_string(root->left->val));
    if (root->right)
        binary_tree_paths(result, root->right, t + "->" + std::to_string(root->right->val));
}

// Solution (Starting point)
std::vector<std::string> binary_tree_paths(TreeNode* root) {

    std::vector<std::string> result;
    if (!root) return result;
 
    binary_tree_paths(result, root, std::to_string(root->val));
    return result;
}



// Demonstration
int main() {

    TreeNode * t1 = new TreeNode(1);
    TreeNode * t2 = new TreeNode(2);
    TreeNode * t3 = new TreeNode(3);
    TreeNode * t5 = new TreeNode(5);

    t1->left = t2;
    t1->right = t3;
    t2->right = t5;

    std::cout << "For binary tree [1,2,3,null,5], paths are: \n";
    for (auto path: binary_tree_paths(t1))
        std::cout << path << ',' << ' ';
    std::cout << std::endl;
}
