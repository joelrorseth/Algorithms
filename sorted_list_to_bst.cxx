//
//  Convert Sorted List to Binary Search Tree
//  https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
//
//  Given a sorted (ascending) singly linked list, construct a height
//  balanced binary search tree.  
//
//  Joel Rorseth
//  Created on August 29, 2017
//

#include <iostream>

// Note: This is the most obvious, simple recursive solution which is
// done with O(n) time and O(1) space complexity. However, it seems a
// faster algorithm would be to make a vector of the linked list, and
// use that similarly to create the bst in order.



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Recursive algorithm to append middle element to BST
// We maintain front and end, end being one past the end of list (eg. null)
TreeNode * to_bst(ListNode * head, ListNode * tail) {

    // Base case -- Return null since list is now empty
    if (head == tail) return NULL;

    // Base case -- Return this single element to be added to BST
    if (head->next == tail) {
        TreeNode * root = new TreeNode(head->val);
        return root;
    }


    ListNode * slow = head;
    ListNode * fast = head;

    // Advance fast / slow pointers to find middle node
    while (fast != tail && fast->next != tail) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Extract middle node and use it as the root for a new tree
    // This new tree will be recursively added to a 'higher' TreeNode

    TreeNode * root = new TreeNode(slow->val);
    root->left = to_bst(head, slow);
    root->right = to_bst(slow->next, tail);

    return root;
}


// Starting point
TreeNode * sorted_list_to_bst(ListNode * head) {
    if (!head) return NULL;
    return to_bst(head, NULL);
}


int main () {}
