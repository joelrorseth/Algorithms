//
//  Longest Palindrome
//  https://leetcode.com/problems/longest-palindrome/
//
//  Determine the length of the longest palindrome that can be 
//  created using letters in a string.
//
//  Joel Rorseth
//  Created on May 29, 2017
//

#include <iostream>
#include <map>

// Solution
int longest_palindrome(std::string s) {

    int res = 0, odd = 0;
    std::map<char, int> m{};

    for (auto ch: s) 
        if (++m[ch] % 2 == 0)
            res += 2;

    for (auto pair: m)
        if (pair.second % 2 != 0) {
            odd = 1;
            break;
        }

    return res + odd;
}

// Demonstration 
int main() {

    std::cout << "The length of the longest palindrome possible using"
        << " \'aabccDDefghh\' is " 
        << longest_palindrome("aabccDDefghh") << std::endl;
}
