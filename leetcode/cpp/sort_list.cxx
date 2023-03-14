//
//  Sort List
//  https://leetcode.com/problems/sort-list
//
//  Write an algorithm to sort a singly linked list in O(n logn) time
//  and constant space complexity.
//
//  Joel Rorseth
//  Created on August 16, 2017
//

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



// Merge algorithm to combine two sorted lists back into one
ListNode * merge(ListNode * left, ListNode * right) {
    ListNode * temp = new ListNode(0);
    ListNode * merged = temp;

    // Sort and reorder the both trivial lists into dummy list
    while (left && right) {

        // Evaluate ordering (both lists are sorted, but not with eachother)
        if (left->val < right->val) {
            merged->next = left;
            left = left->next;
        } else {
            merged->next = right;
            right = right->next;
        }

        merged = merged->next;
    }

    // Tack remaining nodes onto the end of new merged list
    // Only one list (left or right) will still contain nodes now
    if (left) merged->next = left;
    if (right) merged->next = right;

    return temp->next;
}


// Solution (Merge Sort)
ListNode * sortList(ListNode * head) {

    // Base case
    if (!head || !head->next) return head;

    ListNode * prev;
    ListNode * slow = head;
    ListNode * fast = head;

    // Find end of list and split in half using 1/2 speed slow runner
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // 'prev' will be one node before 'slow', 'slow' is start of 'right'
    // 'slow' will be the start of 'right', 'fast' may be null but doesn't matter

    // Terminate 'left' by nulling link to start of 'right'
    prev->next = nullptr;

    // Merge Sort - reursively sort each half
    ListNode * left = sortList(head);
    ListNode * right = sortList(slow);

    return merge(left, right);
}

int main(){}
