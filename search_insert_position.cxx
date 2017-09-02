//
//  Search insert Position
//  https://leetcode.com/problems/search-insert-position
//
//  Given a sorted array and a target value, return the index if 
//  the target is found. If not, return the index where it would be.
//
//  Joel Rorseth
//  Created on September 2, 2017
//

#include <iostream>
#include <vector>


// Solution
int search_insert(std::vector<int> & nums, int target) {
    int idx = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < target) 
            ++idx;

        if (nums[i] == target)
            return i;
    }

    return idx;
}


// Demonstration
int main() {

    std::vector<int> a{1,3,5,6,7};
    std::cout << "Given a={1,3,5,6,7}, search_insert(2)=" 
        << search_insert(a, 2) << std::endl;
}
