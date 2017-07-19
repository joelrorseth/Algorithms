//
//  Minimum Size Subarray Sum
//  https://leetcode.com/problems/minimum-size-subarray-sum
//
//  Given an array of integers, find the minimal length of a contiguous
//  subarray in which the sum of the subarray is >= a given 's'. If no
//  such sum exists, return 0.
//
//  Joel Rorseth
//  Created on July 19, 2017
//

#include <iostream>
#include <vector>
#include <climits>


// Solution
int min_subarray_len(int s, std::vector<int> & nums) {

    int n = nums.size();
    int result = INT_MAX;
    int left = 0, sum = 0;

    // Increase right pointer thru array
    for (int i = 0; i < n; ++i) {

        // Continuously keep track of sum in range [left, i]
        sum += nums[i];

        // Wait until we form range in which contiguous sum >= given 's'
        while (sum >= s) {

            // If new range [left, i] has new min number of elements, set length
            // Increase the left pointer, and update the sum in new [left, i]

            result = std::min( result,  i + 1 - left );
            sum -= nums[left++];
        }
    }

    return (result != INT_MAX) ? result : 0;
}


// Demonstration
int main() {

    std::vector<int> a{2, 3, 1, 2, 4, 3};
    int s = 7;

    std::cout << "Given {2, 3, 1, 2, 4, 3}, " << 
        "the minimum size of subarray with sum >= 7 is " << 
        min_subarray_len(s, a) << std::endl;
}
