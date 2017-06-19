//
//  Next Permutation
//  https://leetcode.com/problems/next-permutation/
//  
//  Implement next permutation, which rearranges numbers into the 
//  lexicographically next greater permutation of numbers. If not
//  possible, rearrange in ascening order.
//
//  Eg. 1, 2, 3  ==>  1, 3, 2
//
//  Joel Rorseth
//  Created on June 19, 2017
//

#include <iostream>
#include <vector>
#include <algorithm>


// Solution
void next_permutation(std::vector<int> & nums) {
    int k = -1, l = -1;

    // Starting at second last index, compare nums[i] to nums[i+1]
    // This finds the index i of leftmost num where nums[i] < nums[i+1]
    for (int i = nums.size() - 2; i >= 0; --i)
        if (nums[i] < nums[i + 1]) {
            k = i;
            break;
        }

    // If there was no nums[k + 1] greater than any nums[k]
    if (k == -1) {
        std::reverse(nums.begin(), nums.end());
        return;
    }

    // Find index of largest num > nums[k] in range (k, end of vector]
    for (int i = nums.size() - 1; i > k; --i)
        if (nums[i] > nums[k]) {
            l = i;
            break;
        }

    // Swap largest num past index k with leftmost num where nums[k] was < nums[k+1]
    std::swap(nums[k], nums[l]);

    // Since that was the largest num, we reverse the sequence starting at k
    std::reverse(nums.begin() + k + 1, nums.end());
}


// Demonstration
int main() {

    std::cout << "next_permutation({1, 2, 3}) = { ";
    
    std::vector<int> a{1, 2, 3};
    next_permutation(a);

    for (auto num: a) 
        std::cout << num << ',' << ' ';
    std::cout << '}' << std::endl;

}
