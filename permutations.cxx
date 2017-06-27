//
//  Permutations
//  https://leetcode.com/problems/permutations/
//
//  Given a list of integers, return a list of all possible 
//  permutations (as a list of permutated sequences).
//
//  Joel Rorseth
//  Created on June 27, 2017
//

#include <iostream>
#include <vector>


// Recursive Permutation Algorithm
void permute_recursive(std::vector<int> & nums, int begin, std::vector<std::vector<int>> & results) {

    if (begin >= nums.size()) {
        results.push_back(nums);
        return;
    }

    // Generate permutations for [begin, actual end]
    for (int i = begin; i < nums.size(); ++i) {

        // Swap current and first in this subset, then permute all of *those*
        std::swap(nums[begin], nums[i]);
        permute_recursive(nums, begin + 1, results);

        // Undo swap
        std::swap(nums[begin], nums[i]);
    }
}

// Solution
std::vector<std::vector<int>> permute(std::vector<int> & nums) {
    std::vector<std::vector<int>> results{};

    permute_recursive(nums, 0, results);
    return results;
}


// Demonstration
int main() {

    std::cout << "All possible permutations of [1,2,3] are:\n";
    std::vector<int> a{1,2,3};

    for (auto sequence: permute(a)) {
        std::cout << '[';
        for (auto number: sequence)
            std::cout << number << ',';

        std::cout << ']' << std::endl;
    }
}
