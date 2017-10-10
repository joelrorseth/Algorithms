//
// Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
//
// Find the kth largest element in an unsorted array. 
//

#include <iostream>
#include <vector>
#include <queue>


int find_kth_largest(std::vector<int> & nums, int k) {
    
    // Create max heap / priority queue from numbers
    std::priority_queue<int> q(nums.begin(), nums.end());

    // Remove greatest n-1 elements
    for (int i = 0; i < k-1; ++i)
        q.pop();

    return q.top();
}


// Demonstration
int main() {

    std::vector<int> nums{1,6,3,2,9,0,7};
    std::cout << "The 3rd largest number in {1,6,3,2,9,0,7} is " 
        << find_kth_largest(nums, 3) << std::endl;
}
