//
//  Combination Sum II
//  https://leetcode.com/problems/combination-sum-ii
//
//  Given a list of numbers and a target sum, return a list of all 
//  unique, possible number combinations whose sum is equal to the target.
//
//  Joel Rorseth
//  Created on July 26, 2017
//

#include <iostream>
#include <vector>
#include <algorithm>


// Solution (Depth First Search)
void dfs(std::vector<int> & candidates, int cur_pos, int target, 
        std::vector<int> & path, std::vector<std::vector<int>> & result) {

    // If target has been reached with contents of path, add to result
    if (target == 0) {
        result.push_back(path);
        return;
    }

    // Path has went over target, go back (will pop last and continue on)
    if (target < 0) return;


    // Go through each candidate number
    // Compose each path using dfs recursion and test for target

    for (int i = cur_pos; i < candidates.size(); ++i) {

        // Skip over this number if we have seen it already in this loop (duplicate)
        if (i > cur_pos && candidates[i] == candidates[i - 1])
            continue;

        // Important: Add number to path, update target to new target value for recursive call
        path.push_back(candidates[i]);
        dfs(candidates, i + 1, target - candidates[i], path, result);

        // Pop last element and continue testing with other numbers in path
        path.pop_back();
    }
}


std::vector<std::vector<int>> combination_sum_2
    (std::vector<int> & candidates, int target) {

    // Sort the input to align duplicates
    std::sort(candidates.begin(), candidates.end(), std::greater<int>());

    std::vector<std::vector<int>> result;
    std::vector<int> path;

    // Search all combinations using a depth first search
    dfs(candidates, 0, target, path, result);
    return result;
}



// Demonstration
int main() {

    std::vector<int> a{10,1,2,7,6,1,5};

    std::cout << "Given list {10,1,2,7,6,1,5} and target = 8, " <<
        "the possible combinations whose sum is 8 is:\n   [";

    for (auto combination: combination_sum_2(a, 8)) {
        std::cout << '[';
        for (auto number: combination)
            std::cout << number << ',';
        std::cout << ']' << ',';
    }

    std::cout << ']' << std::endl;
}
