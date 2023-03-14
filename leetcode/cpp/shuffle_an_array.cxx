//
//  Shuffle An Array
//  https://leetcode.com/problems/shuffle-an-array
//  
//  Create functions to shuffle and reset an array.
//
//  Joel Rorseth
//  Created on June 12, 2017
//

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
    std::vector<int> original;

public:
    Solution(std::vector<int> nums) {
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() {

        // Vector for random arrangement
        std::vector<int> randomized(original);

        for (int i = 0; i < randomized.size(); i++) {

            // Pick a number to swap with from the remaining portion of array
            int pos = rand() % (randomized.size()-i);
            std::swap(randomized[i+pos], randomized[i]);
        }

        return randomized;
    }
};


int main() {

    Solution a{ {1,2,3,4,5,6,7,8,9,0} };

    std::cout << "Original vector: {";
    for (auto i: a.reset())
        std::cout << i << ',';
    
    std::cout << "}\nShuffled vector: {";
    for (auto i: a.shuffle())
        std::cout << i << ',';
    std::cout << '}' << std::endl;
}
