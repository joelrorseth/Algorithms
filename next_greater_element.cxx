//
//  Next Greater Element I
//  https://leetcode.com/problems/next-greater-element-i
//  
//  Given a two lists of integers, list2 and list2, where list1 is a
//  subset of list2, return a new list where for each element in list1, 
//  the next greatest number appearing to the right of that value in 
//  list2 is inserted into the returned list. Insert -1 if n/a.
//
//  Input: list1 = [4,1,2], list2 = [1,3,4,2].
//  Output: [-1,3,-1]
//
//  Joel Rorseth
//  Created on May 24, 2017
//

#include <iostream>
#include <map>
#include <vector>

// Solution
std::vector<int> next_greater_element(std::vector<int>& findNums, std::vector<int>& nums) {

    std::map<int, int> location{};
    std::vector<int> retval{};

    // Make a map for quick position lookup of 'nums' elements
    for (int i = 0; i < nums.size(); i++) 
        location.insert(std::make_pair(nums[i], i));

    for (auto num: findNums) {

        int num_index = location[num];
        bool found = false;

        // Loop through right section of nums to find number >
        for (int j = num_index + 1; j < nums.size(); j++) 
            if (nums[j] > num) {
                retval.push_back(nums[j]);
                found = true;
                break;
            }
        
        // Detect if value > num wasn't found, insert -1
        if (!found)
            retval.push_back(-1);
    }

    return retval;
}

// Demonstration
int main() {
    
    std::vector<int> lista{4,1,2};
    std::vector<int> listb{1,3,4,2};

    std::cout << "List A: [4,1,2],  List B: [1,3,4,2]\n";
    std::cout << "Output: [";
    for (auto i: next_greater_element(lista, listb))
        std::cout << i << ',';
    std::cout << ']' << std::endl;
}
