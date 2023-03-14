//
// Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/
//
// November 24, 2017
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>


// Solution
std::vector<int> top_k_frequent(std::vector<int> & nums, int k) {

    // Make histogram map for input
    std::unordered_map<int, int> freq;
    for (int n: nums) 
        ++freq[n];

    std::vector<int> most_freq;

    std::priority_queue<std::pair<int, int>> pq;

    for (auto it = freq.begin(); it != freq.end(); it++) {

        // Put this frequency mapping into priority queue
        // Make sure it sorts by frequency (put it first in pair)

        pq.push(std::make_pair(it->second, it->first));
    }

    for (int i = 0; i < k; ++i) {
        most_freq.push_back(pq.top().second);
        pq.pop();
    }

    return most_freq;
}


// Demonstration
// TODO: Does not compile, not sure why worked fine on Leetcode
int main() {
    
    std::vector<int> a{1,2,3,4,1,2,3,1,2,1};
    
    std::cout << "Numbers: ";
    for (const auto n: a)
        std::cout << n << ',';

    std::cout << "\n2 Most Frequent: ";
    for (const auto n: top_k_frequent(a, 2))
        std::cout << n << ',';
    std::cout << std::endl;
}
