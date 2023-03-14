//
// Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
//
// Given a string, determine the longest substring that is a valid palindrome.
//

#include <iostream>

class Solution {
public:
    
    // Keep best current answer in instance variables
    int longest_start, longest_length;
    
    
    void expand_around_center(const std::string & s, int left, int right) {
        
        // Move start and end positions away eachother as
        // long as the range still defines a palindrome
        
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left; ++right;
        }
        
        
        // If this palindrome was longer, update current longest
        if (longest_length < right - left - 1) {
            
            longest_length  = right - left - 1;
            longest_start = left + 1;
        }
    }
    
    
    std::string longest_palindrome(std::string s) {
        
        // Edge case: 0 or 1 characters is itself a palindrome
        if (s.size() < 2) return s;
        
        for (int i = 0; i < s.size() - 1; ++i) {
            
            expand_around_center(s, i, i);      // Find odd length palindromes
            expand_around_center(s, i, i+1);    // Find even length palindromes
        }
        
        return s.substr(longest_start, longest_length);
    }
};



// Demonstration
int main() {
    
    auto solution = Solution();
    std::string s{"babad"};
    
    auto longest = solution.longest_palindrome(s);
    
    std::cout << "The longest palindromic substring of \"" <<
        s << "\" is \"" << longest << "\"" << std::endl;
}
