//
//  Reverse String
//  https://leetcode.com/problems/reverse-string
//
//  Given a string, return the string reversed. 
//
//  Joel Rorseth
//  Created on May 24, 2017
//

#include <iostream>
#include <string>
#include <stack>

// Solution
std::string reverse_string(std::string s) {
    std::stack<char> rev{};
    std::string retval{};

    for (auto ch: s)
        rev.push(ch);

    while (!rev.empty()) {
        retval.push_back(rev.top());
        rev.pop();
    }

    return retval;
}

// Demonstration
int main() {
    
    std::string str{"hello"};
    
    std::cout << "Input: " << str << '\n';
    std::cout << "Output: " << reverse_string(str) << std::endl;
}
