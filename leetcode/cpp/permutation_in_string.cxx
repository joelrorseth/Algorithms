//
//  Permutation in String
//  https://leetcode.com/problems/permutation-in-string/
//  
//  Given two strings s1 and s2, determine if s2 contains
//  a permutation of s1.
//
//  s1 = "ab"
//  s2 = "eidbaooo"     => true
//
//  Joel Rorseth
//  Created on May 18, 2017
//

#include <iostream>
#include <vector>

// Helper function
bool all_zero(std::vector<int> count) {
    for (int i = 0; i < 26; i++) 
        if (count[i] != 0) return false;
        
    return true;
}

// Solution
bool check_inclusion(std::string s1, std::string s2) {

    // In this case, impossible for s2 to contain all of s1
    if (s1.length() > s2.length()) return false;

    std::vector<int> count(26, 0);

    // All characters found equally in s1 and s2 with have count 0
    for (int i = 0; i < s1.length(); i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }

    // If all count are 0, all characters in s1 were matched in s2
    if (all_zero(count)) return true;

    for (int i = s1.length(); i < s2.length(); i++) {
        count[s2[i] - 'a']--;
        count[s2[i - s1.length()] - 'a']++;

        if (all_zero(count)) return true;
    }

    return false;
}

// Demonstration
int main() {

    std::string const s1{"ab"}, s2{"eidbaooo"};

    std::cout << "s1 = " << s1 << "\ns2 = " << s2 
        << "\ncheck_inclusion(s1, s2) = " << check_inclusion(s1, s2);
}
