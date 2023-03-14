//
//  Search for a Range
//  https://leetcode.com/problems/search-for-a-range/
//
//  Given a sorted array, containing a range of identical numbers
//  appearing in order beside eachother, determine the start and end
//  points of this range. This must be done is O(lg n) time.
//
//  Joel Rorseth
//  Created on June 26, 2017
//

#include <iostream>
#include <vector>

// Solving any problem with O(log n) complexity usually involves
// binary sorting. Since the array is sorted, we can halve it each
// time, performing two searches in total (one for each endpoint)


// Solution (Modified binary search)
std::vector<int> search_range(std::vector<int> & nums, int target) {

    if (nums.size() == 0)
        return std::vector<int>{-1, -1};

    // Create left and right bounds for binary search
    int i = 0, j = nums.size() - 1;
    std::vector<int> retval{-1, -1};

    // Search for start / leftmost index
    while (i < j) {
        int mid = (i + j) / 2;

        // If target is to the right, increase lower bound
        // Else decrease upper bound
        if (nums[mid] < target) i = mid + 1;
        else j = mid;
    }

    if (nums[i] != target) return retval;
    else retval[0] = i;



    // Reset upper bound, leave lower (now situated one past lower bound!)
    j = nums.size() - 1;

    // Search for the end / rightmost index
    while (i < j) {
        int mid = (i + j) / 2 + 1;

        // If target is to the left, decrease upper bound
        // Else increase lower bound
        if (nums[mid] > target)  j = mid - 1;
        else i = mid;
    }

    retval[1] = j;
    return retval;
}


// Demonstration
int main() {

    std::vector<int> a{1,2,3,4,4,4,4,5,7,9};
    std::vector<int> retval = search_range(a, 4);
    
    std::cout << "Given a = {1,2,3,4,4,4,4,5,7,9}, search_range(a, 4) = {"
        << retval[0] << ',' << ' ' << retval[1] << '}' << std::endl;
}
