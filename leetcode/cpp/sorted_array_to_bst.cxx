//
// Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//
// Given an array of integers in sorted, ascending order, create a binary search
// tree with balanced height (as balanced as possible).
//

#include <iostream>
#include <vector>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

// Solution (Insert middle element, then split into left/right subarrays)
TreeNode * sortedArrayToBST(std::vector<int> & nums) {
    
    // Edge case: No numbers left to insert
    if (nums.empty()) return NULL;
    
    // Calculate midpoint (next logical insertion for balanced height BST)
    auto mid = nums.size() / 2;
    
    // Splice into left and right vectors about midpoint
    std::vector<int> left(nums.begin(), nums.begin() + mid);
    std::vector<int> right(nums.begin() + mid + 1, nums.end());
    
    // Construct BST, letting algo recursively determine next node in left/right tree
    TreeNode * root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);
    
    return root;
}

int main() {}
