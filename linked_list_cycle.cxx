//
// Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/
//
// Determine if a singly linked list contains a cycle
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Think of it like a circular track. If two people race, and one is twice
// as fast, the fast runner will eventually 'lap' the slow runner as long as
// the track is fully circular (eg. a cycle!)

bool has_cycle(ListNode * head) {
    
    if (!head || !head->next)
        return false;
    
    ListNode * slow = head;
    ListNode * fast = head->next;
    
    while (fast != slow) {
        
        // If runner has reached the end, cycle is impossible
        if (!fast || !slow || !fast->next)
            return false;
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // If fast has 'lapped' slow, it must have found a cycle
    return true;
}

int main() {}
