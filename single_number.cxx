//
//  Single Number
//  https://leetcode.com/problems/single-number/
//
//  Given an array where every number appears twice except for one,
//  find the element that occurs only once.
//
//  Joel Rorseth
//  Created on May 29, 2017
//

#include <iostream>
#include <vector>

// Solution: Every time we XOR result with another number, it will
// keep changing result. When it sees a number that has already been
// used to change, it will effectively undo the change. After undoing
// all, you are left with the only one that hasn't been changed back.


// Solution
int single_number(std::vector<int> & nums) {

    int result = 0;
    for (auto n: nums)
        result = result ^ n;

    return result;
}


// Demonstration
int main() {

    std::vector<int> list{1,1,2,2,3,3,4,5,5};
    std::cout << "List: {1,1,2,2,3,3,4,5,5}, single_number(List) = "
        << single_number(list) << std::endl;
}
