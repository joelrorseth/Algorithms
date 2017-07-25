//
//  Minimum Height Trees
//  https://leetcode.com/problems/minimum-height-trees
//
//  Given a graph (a list of pairs of connected nodes in a graph), 
//  write a function to find all minimum height trees, returning them
//  in a list of their root labels.
//
//  Eg. Given n=6,  edges= [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
//
//  0  1  2
//   \ | /
//     3           returns [3, 4]
//     |
//     4
//     |
//     5
//
//  Joel Rorseth
//  Created on July 24, 2017
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>


// Solution
std::vector<int> find_min_height_trees(int n, std::vector<std::pair<int, int>> & edges) {

    std::vector<std::unordered_set<int>> adjacent(n);

    // Populate an adjacency list
    // Each index (representing a node) contains set of all adjacent nodes

    for (std::pair<int, int> edge: edges) {
        adjacent[edge.first].insert(edge.second);
        adjacent[edge.second].insert(edge.first);
    }

    std::vector<int> leaves{};
    
    if (n == 1) {
        leaves.push_back(0);
        return leaves;
    }

    
    // Populate a list of all leaf nodes (nodes with only one edge)
    for (int i = 0; i < (int)adjacent.size(); ++i)
        if (adjacent[i].size() == 1)
            leaves.push_back(i);

    
    while (true) {

        std::vector<int> next;

        // For each leaf node, go thru each it's neighbors (should only be 1)
        for (auto leaf: leaves) {
            for (auto neighbor: adjacent[leaf]) {

                // Remove the leaf from list of neighbor's adjacent nodes
                adjacent[neighbor].erase(leaf);

                // If after removing that adjacent node, this neighbor is a leaf node,
                // add this node into the returned list. This chops off all leaf nodes
                // to leave only same 'minimal height' roots at the end

                if (adjacent[neighbor].size() == 1)
                    next.push_back(neighbor);
            }
        }

        if (next.empty())
            return leaves;

        leaves = next;
    }
}


// Demonstration
int main() {

    std::vector<std::pair<int, int>> input = {{0,3}, {1,3}, {2,3}, {4,3}, {5,4}};
    int n = 6;		// # of actual nodes (eg. 0, 1, 2, 3, 4, 5)

    std::cout << "Given n=6, edges=[[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]"
        << "\nMinimum Height Tree root nodes: [";

    for (int root: find_min_height_trees(n, input))
        std::cout << root << ',';
    std::cout << ']' << std::endl;
}
