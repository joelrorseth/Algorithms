//
// Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/
//
// Reverse a singly linked list
//

#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Solution tracks a previous node, and sets current's next to previous
ListNode * reverseList(ListNode * head) {
    
    // Edge case: Empty list
    if (!head) return head;
    
    ListNode * current = head;
    ListNode * previous = NULL;
    
    while (current) {
        
        // Store next in list and change its next pointer to previous element
        ListNode * next = current->next;
        current->next = previous;
        
        // Update for new previous
        previous = current;
        
        // Update current to be original next
        current = next;
    }
    
    return previous;
}


int main() {}
