//
//  Reverse Words in a String III
//  https://leetcode.com/problems/reverse-words-in-a-string-iii
//
//  Given a string containing words separated by single space 
//  characters, return a new string containing the same words 
//  separated by spaces, but reversed.
//
//  Input: "Let's take LeetCode contest"
//  Output: "s'teL ekat edoCteeL tsetnoc"
//
//  Joel Rorseth
//  Created on May 24, 2017
//

#include <iostream>
#include <string>
#include <stack>


// Solution
std::string reverse_words(std::string s) {

    std::string reversed{};
    std::stack<char> hold{};

    for (auto ch: s) {

        if (ch == ' ') {
            while (!hold.empty()) {
                reversed.push_back(hold.top());
                hold.pop();
            }
            reversed.push_back(ch);

        } else 
            hold.push(ch);

    }

    while (!hold.empty()) {
        reversed.push_back(hold.top());
        hold.pop();
    }

    return reversed;
}

// Demonstration
int main() {

    std::string str{"Let's take LeetCode contest"};
    std::cout << "Input: " << str << '\n';

    std::cout << "Output: " << reverse_words(str) << std::endl;
}
