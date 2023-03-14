//
//  Keyboard Row
//  https://leetcode.com/problems/keyboard-row/
//  
//  Given a list of words, return a new list containing
//  all words that can be typed using only one row on a
//  standard USA ASCII keyboard.
//
//  Joel Rorseth
//  Created on May 15, 2017
//

#include <iostream>
#include <regex>
#include <vector>

// Solution
std::vector<std::string> find_words(std::vector<std::string>& words) {

    std::vector<std::string> retval{};
    std::regex regularexp("[qwertyuiopQWERTYUIOP]*|[asdfghjklASDFGHJKL]*|[zxcvbnmZXCVBNM]*");

    // Match words against regex
    for (auto word: words) 
        if (regex_match(word, regularexp))
            retval.push_back(word);        

    return retval;
}


// Print function
void print_list(std::vector<std::string> const & words) {
    for (auto word: words)
        std::cout << word << ", ";
    std::cout << std::endl;
}


// Demonstration
int main(int argc, char * argv[]) {

    std::vector<std::string> list{"Hello", "Alaska", "Dad", "Peace"};
    
    std::cout << "Original list...\n\t";
    print_list(list);

    std::cout << "\nWords contained within one keyboard row...\n\t";
    print_list( find_words(list) );
}
