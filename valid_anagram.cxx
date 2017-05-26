//
//  Valid Anagram
//  https://leetcode.com/problems/valid-anagram/
//  
//  Determine if two words are valid anagrams.
//  s = "anagram", t = "nagaram"  ==> true
//
//  Joel Rorseth
//  Created on May 26, 2017
//

#include <iostream>
#include <map>

// Solution
bool is_anagram(std::string s, std::string t) {
    std::map<char, int> c1, c2;

    // If anagram, each map has same character occurence count
    for (auto ch: s)
        c1[ch]++;
    for (auto ch: t)
        c2[ch]++;

    return c1 == c2;
}

// Demonstration
int main() {

    std::cout << "is_anagram(anagram, nagaram) = " 
        << (is_anagram("anagram", "nagaram") ? "true" : "false")
        << std::endl;
}
