//
//  Partition List
//  https://leetcode.com/problems/partition-list
//
//  Given a singly linked list and a value x, partition it such that
//  all numbers less than x come before all other numbers greater than
//  or equal to x. The relative order should be maintained.
//
//  Joel Rorseth
//  Created on July 7, 2017
//

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Solution
ListNode* partition(ListNode* head, int x) {

    ListNode lessThan{0};
    ListNode greaterThanOrEqual{0};
    ListNode * lessCurrent = &lessThan;
    ListNode * greaterCurrent = &greaterThanOrEqual;

    while (head) {

        ListNode * & list = (head->val < x) ? lessCurrent : greaterCurrent;
        list->next = head;   

        list = list->next;
        head = head->next;
    }

    lessCurrent->next = greaterThanOrEqual.next;
    greaterCurrent->next = NULL;
    return lessThan.next;
}

int main(){}
