//
// Merge Intervals
// https://leetcode.com/problems/merge-intervals/
//
// Given an unsorted array of time intervals, return a new array such 
// that the overlapping intervals have been merged.
//

#include <iostream>
#include <vector>
#include <algorithm>

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};



// Solution -- O(n logn) + O(n)
std::vector<Interval> merge(std::vector<Interval> & intervals) {

    if (intervals.empty()) return std::vector<Interval>();

    // Must sort by start time to be able to compare easily in O(n)
    // Sorting guarantees an interval with lower start time will appear when iterating

    std::sort(intervals.begin(), intervals.end(), 
            [](Interval a, Interval b) { return a.start < b.start; });


    std::vector<Interval> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
        auto interval = intervals[i];

        auto start = interval.start;
        auto end = interval.end;

        // If no overlap, add directly
        if (merged.back().end < start) 
            merged.push_back(interval);

        // If range overlaps, extend it to the furthest end of the two
        else 
            merged.back().end = std::max(merged.back().end, end);

    }

    return merged;
}




// Demonstration
int main() {

    Interval i1(1,4);
    Interval i2(0,4);
    Interval i3(7,9);
    Interval i4(6,10);

    std::vector<Interval> intervals{i1,i2,i3,i4};
    std::cout << "Given the intervals [1,4],[0,4],[7,9],[6,10], the merged "
        << " intervals are: ";

    for (const auto & interval: merge(intervals)) 
        std::cout << '[' << interval.start << ',' << interval.end << "],";

    std::cout << std::endl;
}
