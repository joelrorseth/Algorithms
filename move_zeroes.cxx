//
//  Move Zeros
//
//  https://leetcode.com/problems/move-zeroes/
//  Rearragne an array of numbers to move all zeroes to
//  the end, while maintain order. Do this in place.
//
//  Eg. {1,0,4,3,0} -> {1,4,3,0,0}
//
//  Joel Rorseth
//  Created on May 16, 2017
//

#include <iostream>
#include <vector>
#include <algorithm>

// Even better solution
void move_zeroes_efficient(std::vector<int> & nums) {
    std::fill( std::remove(nums.begin(), nums.end(), 0) , nums.end(), 0);
}

// Solution
void move_zeroes(std::vector<int> & nums) {

    auto current = 0;

    for (int j = 0; j < nums.size(); ++j)
        if (nums[j] != 0) 
            nums[current++] = nums[j];

    for (int k = current; k < nums.size(); ++k)
        nums[k] = 0;
}


// Demonstration
int main(int argc, char * argv[]) {

    std::vector<int> nums{5,8,0,3,0,4,6,0,2,0,1,3};

    std::cout << "Original array: {";
    for (auto num: nums)
        std::cout << num << ',' << ' ';
    std::cout << '}' << std::endl;

    move_zeroes_efficient(nums);

    std::cout << "After moving zeroes: {";
    for (auto num: nums)
        std::cout << num << ',' << ' ';
    std::cout << '}' << std::endl;
}
