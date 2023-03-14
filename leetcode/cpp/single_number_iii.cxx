//
//  Single Number III
//  https://leetcode.com/problems/single-number-iii/
//
//  Given an array where every number appears twice except for two,
//  return a vector with both numbers that occur only once.
//
//  Joel Rorseth
//  Created on June 13, 2017
//

#include <iostream>
#include <numeric>
#include <vector>

// Solution
std::vector<int> single_number(std::vector<int> & nums) {

    // Obtain the XOR of the two numbers that occur twice
    auto diff = std::accumulate(nums.begin(), nums.end(), 0, 
            [](int a, int b) { return a ^ b; });

    // Find any bit where the bits of two target numbers were different
    // We choose to use and store the rightmost bit from the original diff
    diff &= -diff;

    std::vector<int> retval = {0, 0};

    for (auto num: nums) {

        // Divide all numbers into two groups: numbers with the diff
        // bit set, and numbers where it is not set! This is because we
        // are expecting two numbers, and this is how to differentiate

        if ((num & diff) == 0)  // Bit not set
            retval[0] ^= num;
        else
            retval[1] ^= num;   // Bit is set

        // All duplicates above will 'undo' themselves from the result,
        // and since each target number is in a different 'group',
        // one target will be left in each vector position
    }

    return retval;
}


// Demonstration
int main() {

    std::vector<int> a{1,2,1,3,2,5};
    std::cout << "Given vector {1,2,1,3,2,5}, single_number(vector) = {";

    for (auto num: single_number(a))
        std::cout << num << ',';
    std::cout << '}' << std::endl;
}
