//
//  Remove Nth From Last
//  https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//
//  Remove the node nth from the last node in a linked list,
//  and return the head to the new list.
//
//  Joel Rorseth
//  Created on August 10, 2017
//

#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Solution
ListNode* remove_nth_from_end(ListNode * head, int n) {

    //Pointer to the head pointer
    ListNode ** slow = &head;

    // Fast pointer to move n nodes ahead
    ListNode * fast = head;
    for (int i = n; i > 1; --i) 
        fast = fast->next;

    // Increment fast and slow until end is reached
    while (fast->next != NULL) {
        fast = fast->next;
        slow = &((*slow)->next);
    } 

    *slow = (*slow)->next;
    return head;
}

int main(){}
