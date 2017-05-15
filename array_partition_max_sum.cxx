//
//  Array Partition I
//  https://leetcode.com/problems/array-partition-i
//
//  Partition array of size n into n/2 ordered pairs, such 
//  that the summation of minimums of all pairs, min(ai,bi) 
//  for all i...n, is the maximum possible.
//
//  Joel Rorseth
//  Created on May 12, 2017
//

#include <iostream>


// Solution
int array_partition_max_sum(std::vector<int>& nums) {

    // Best order to make ordered pairs is sorted
    // Each pair will be taken two at a time starting at beginning
    
    std::sort(nums.begin(), nums.end());

    int sum = 0;
    bool every_other = true;

    // Starting at first element, add every other num to summation
    // This is because every other element is the first element in 
    // anordered pair

    for (auto num: nums) {
        if (every_other)
            sum += num;
        every_other = !every_other;
    }

    return sum;
}

// Demonstration
int main() {

    std::vector a{1,6,3,8,2,3,4,7};
    auto result = array_partition_max_sum(a);

    std::cout << "Original vector...\n\t;
    for (auto i: a)
        std::cout << i << ' ';
    
    std::cout<< "\nThe maximum sum after arranging into ordered pairs is"
        << result << std::endl;
}
