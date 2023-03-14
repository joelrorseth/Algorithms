//
//  Intersection of Two Arrays
//  https://leetcode.com/problems/intersection-of-two-arrays/
//  
//  Return an array containing elements that appear in both
//  given arrays (the intersection).
//
//  Joel Rorseth
//  Created on May 30, 2017
//

#include <iostream>
#include <vector>
#include <unordered_set>

// Solution
std::vector<int> intersection
(std::vector<int>& nums1, std::vector<int>& nums2) {

    std::unordered_set<int> hold{nums1.begin(), nums1.end()};
    std::unordered_set<int> retval{};

    for (auto n: nums2) 
        if (hold.count(n)) 
            retval.insert(n);

    return std::vector<int>{retval.begin(), retval.end()};
}

// Demonstration
int main() {

    std::vector<int> a{1,2,3,4};
    std::vector<int> b{5,3,4};

    std::cout << "The intersection of {1,2,3,4} and {5,3,4} is {";
    for (auto num: intersection(a, b))
        std::cout << num << ',';
    std::cout << '}' << std::endl;
}
