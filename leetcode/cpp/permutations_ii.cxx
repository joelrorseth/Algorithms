//
//  Permutations II
//  https://leetcode.com/problems/permutations-ii
//
//  Given a sequence of numbers (that may contain duplicates), determine
//  all unique permutations that can be arranged using this input.
//
//  Joel Rorseth
//  Created on July 5, 2017
//

#include <iostream>
#include <vector>
#include <algorithm>


// Solution
void find_unique_permutations(std::vector<int> nums, int start, int end, std::vector<std::vector<int>> & result) {

    // Add current sequence when start index == end index
    if (start == end - 1) {
        result.push_back(nums);
        return;
    }

    // Loop through every k in [start, end)
    // Swap number at start index and k then recurse on remainder
    for (int k = start; k < end; ++k) {
        if (start != k && nums[start] == nums[k]) 
            continue;

        std::swap(nums[start], nums[k]);
        find_unique_permutations(nums, start + 1, end, result);
    }
}

std::vector<std::vector<int>> permute_unique(std::vector<int> & nums) {

    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> result;
    find_unique_permutations(nums, 0, nums.size(), result);

    return result;
}


// Demonstration
int main() {

    std::vector<int> a{1,1,2,3};

    std::cout << "Unique permutations of [1,1,2,3] are:\n";
    for (auto sequence: permute_unique(a)) {

        std::cout << '[';
        for (auto n: sequence)
            std::cout << n << ',';
        std::cout << ']' << ',' << ' ';
    }

    std::cout << std::endl;
}
