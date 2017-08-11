//
//  Minimum Genetic Mutation
//  https://leetcode.com/problems/minimum-genetic-mutation
//
//  You are given DNA sequences, where each is a combination of 8 
//  letters from the set [A,C,G,T]. Given a start and end sequence,
//  and a bank of valid 'mutation' sequences, determine the minimum 
//  number of mutations to transform 'start' to 'end' by changing only
//  one letter at a time. All in-between sequences must be in the bank
//  to be considered valid.
//
//  eg.  Start:  AAAAACCC      End:  AACCCCCC
//       Bank: [AAAACCCC ,  AAACCCCC ,  AACCCCCC]
//
//       Return: 3
//
//  Joel Rorseth
//  Created on August 11, 2017
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>


// Add all mutations that can come after a word to queue (will differ by 1 char)
void add_word(std::string word, std::unordered_set<std::string> & dict, 
        std::queue<std::string> & bfs_visit) {

    // Remove the given word from the set
    dict.erase(word);

    // Go thru each letter in the word being tested
    // We will look for mutations one character away
    for (int i = 0; i < word.size(); ++i) {
        char original_letter = word[i];

        // Swap that letter out with each possible letter
        for (auto c: std::string("ACGT")) {
            word[i] = c;

            // If that mutation actually exists in the dict, then add it into the queue!
            // All mutations one character away will be added to queue
            if (dict.count(word) != 0) {
                bfs_visit.push(word);
                dict.erase(word);
            }
        }

        word[i] = original_letter;
    }
}


// Solution
int min_mutation(std::string start, std::string end, std::vector<std::string>& bank) {

    std::queue<std::string> bfs_visit;
    std::unordered_set<std::string> dict(bank.begin(), bank.end());

    int distance = 0;

    // If the bank of eligable mutations doesn't contain the end, then impossible
    if (dict.count(end) == 0) return -1;

    bfs_visit.push(start);
    dict.insert(start);
    dict.insert(end);


    // Perform breadth first search. Using a queue, we will find every possible
    // next mutation (one character away), then in turn, test for their next (BFS)

    while (!bfs_visit.empty()) {
        auto n = bfs_visit.size();

        for (int i = 0; i < n; ++i) {

            // Return distance if the bfs has finished the path
            auto mutation = bfs_visit.front();
            if (mutation == end) return distance;

            bfs_visit.pop();
            add_word(mutation, dict, bfs_visit);
        }

        ++distance;
    }

    return -1;
}



// Demonstration
int main() {

    std::string start{"AACCGGTT"}, end{"AAACGGTA"};
    std::vector<std::string> bank{"AACCGGTA","AACCGCTA","AAACGGTA"};

    std::cout << "Start: AACCGGTT\nEnd: AAACGGTA\nBank:["
        << "AACCGGTA, AACCGCTA, AAACGGTA]\n"
        << "Minimum genetic mutation distance: "
        << min_mutation(start, end, bank) << std::endl;
        
}
