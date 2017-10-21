//
// Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings/
//
// Given a string, determine how many palindromic substrings are contained
// within it.
//

#include <iostream>


// Solution
int count_substrings(std::string s) {
    
    int count = 0;
    
    // Consider each possible palindrome center, of which there shoud be 2N-1
    for (int center = 0; center < (2 * s.size() - 1); ++center) {
        
        // Should alternate between picking one or two element range each iteration
        // This is the proper (smallest) starting point to expand from and find palindromes
        
        int left = center / 2;
        int right = left + center % 2;
        
        // std::cout << "L:" << left << " R:" << right << std::endl;
        
        // While still a plaindrome, expand outwards from center (to check if palindrome)
        // Keep extending and increment plaindrome count as long as left still = right
        
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            // std::cout << "  Count now " << count << std::endl;
            
            ++count;
            ++right;
            --left;
        }
    }
    
    return count;
}


// Demonstration
int main() {
 
    std::string s{"aaa"};
    std::cout << "There are " << count_substrings(s) << " palindromic substrings"
        << " in the string \"" << s << "\"" << std::endl;
}
