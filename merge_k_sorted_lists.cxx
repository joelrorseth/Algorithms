//
// Merge K Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
//
// Merge k sorted linked lists into one sorted linked list.
// Worst case time complexity: O(N log k)
//

#include <iostream>
#include <vector>
#include <utility>
#include <queue>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



// Custom function object used as for ordering pq_element's ascending
struct Compare {
    using pq_element = std::pair<int, ListNode *>;
    
    constexpr bool operator()(pq_element const & a, pq_element const & b) const noexcept {
        return a.first > b.first;
    }
};


class Solution {
public:
    
    // This solution simply puts every list into a priority queue. std::priority_queue
    // stores std::pair's of each head and its value, ordering using the value (pair compares
    // lexicographically from left to right, value is stored in leftmost pair element). Once
    // queue picks lowest, reinsert head->next and pick lowest from every list again.
    
    
    ListNode * merge_k_lists(std::vector<ListNode*> & lists) {
        
        ListNode * temp = new ListNode(0);
        ListNode * head = temp;
        
        std::priority_queue<
            std::pair<int, ListNode *>,
            std::vector<std::pair<int, ListNode *>>,
            Compare> q;
        
        // Add each list and its head to a priority queue
        for (const auto & list: lists)
            if (list)                       // Head could be null - empty list
                q.push({ list->val, list });
        
        
        // Take the next 'lowest' element in the priority queue...
        while (!q.empty()) {
            
            const auto next = q.top();
            q.pop();
            
            const auto value = next.first;
            auto node = next.second;
            
            // Make new node with this value, insert into final sorted list
            temp->next = new ListNode(value);
            temp = temp->next;
            
            // Go to next node in list we pulled from, reinsert with next head (lowest in its list)
            node = node->next;
            if (node) q.push({ node->val, node });
        }
        
        return head->next;
    }
};



// Print a linked list
void print_list(ListNode * head) {
    while (head) {
        std::cout << head->val << ' ';
        head = head->next;
    }
    
    std::cout << std::endl;
}



// Demonstration
int main() {
    
    ListNode * a00 = new ListNode(1);
    ListNode * a01 = new ListNode(3);
    ListNode * a02 = new ListNode(4);
    a00->next = a01;
    a01->next = a02;
    
    ListNode * a10 = new ListNode(0);
    ListNode * a11 = new ListNode(5);
    ListNode * a12 = new ListNode(6);
    a10->next = a11;
    a11->next = a12;
    
    std::cout << "List 1: ";
    print_list(a00);
    std::cout << "List 2: ";
    print_list(a10);
    
    std::vector<ListNode *> lists{a00, a10};
    
    std::cout << "Merged and sorted: ";
    auto solution_obj = Solution();
    print_list( solution_obj.merge_k_lists(lists) );
}
