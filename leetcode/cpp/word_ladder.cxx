//
// Word Ladder
// https://leetcode.com/problems/word-ladder/
//
// Given a start word, end word, and a dictionary of valid words, determine the length of the
// shortest transformation sequence from begin to end. To transform begin into end, each
// word in the sequence must only change one character at a time, and must be present in the
// dictionary of valid words.
//
// Eg.  start="hit",  end="cog",  valid=["hot","dot","dog","lot","log","cog"]
//       -->  "hit" -> "hot" -> "dot" -> "dog" -> "cog"  and thus returns 5
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>


// Add all valid words that can come after 'begin_word' to 'next'
void find_next(std::string begin_word, std::unordered_set<std::string> & words,
               std::queue<std::string> & next) {
    
    words.erase(begin_word);
    
    // For each character in 'begin_word'...
    for (int p = 0; p < (int)begin_word.length(); p++) {
        char letter = begin_word[p];
        
        // Try changing this character, then check if this new changed word in in 'words'
        for (int k = 0; k < 26; k++) {
            begin_word[p] = 'a' + k;
            
            if (words.find(begin_word) != words.end()) {
                next.push(begin_word);
                words.erase(begin_word);
            }
        }
        
        begin_word[p] = letter;
    }
}


int ladder_length(std::string begin_word, std::string end_word,
                  std::vector<std::string> & word_list) {
    
    // For lookup efficiency, convert vector to unordered_set  eg. O(1) lookups
    std::unordered_set<std::string> words(word_list.begin(), word_list.end());
    
    
    std::queue<std::string> next;
    find_next(begin_word, words, next);
    
    int dist = 2;
    
    // Start BFS
    while (!next.empty()) {
        int num = next.size();
        
        // Because find_next() can add many candidates each call,
        // go thru each for this while loop iteration
        
        for (int i = 0; i < num; i++) {
            
            std::string word = next.front();
            next.pop();
            
            // Check for path end, return distance when found
            if (word == end_word) return dist;
            find_next(word, words, next);
        }
        
        dist++;
    }
    
    return 0;
}


// Demonstration
int main() {
    
    std::string begin{"hit"};
    std::string end{"cog"};
    std::vector<std::string> words{"hot","dot","dog","lot","log","cog"};
    
    std::cout << "Begin: " << begin << "\nEnd: " << end << "\nWords: ";
    for (std::string & s: words)
        std::cout << s << ',';
    
    std::cout << "\nShortest transformation length: " <<
        ladder_length(begin, end, words) << std::endl;
}
