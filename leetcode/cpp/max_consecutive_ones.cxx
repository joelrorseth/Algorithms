//
//  Max Consecutive Ones
//  https://leetcode.com/problems/max-consecutive-ones/
//  
//  Determine the longest sequence of 1's in a binary array
//
//  Joel Rorseth
//  Created on May 26, 2017
//

#include <iostream>
#include <vector>

// Solution
int find_max_consecutive_ones(std::vector<int> & nums) {

    int c = 0, save = 0;

    for (auto n: nums) {
        if (n) {
            ++c;
            if (c > save)
                save = c;
        } else c = 0;
    }

    return save;
}

// Demonstration
int main() {

    std::vector<int> b{0,1,1,1,0,1,1};
    std::cout << "Max consecutive ones in [0,1,1,1,0,1,1] = "
        << find_max_consecutive_ones(b) << std::endl;
}
