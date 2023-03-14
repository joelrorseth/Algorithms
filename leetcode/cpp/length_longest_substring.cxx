//
//  Longest Substring Without Repeating Characters
//  https://leetcode.com/problems/longest-substring-without-repeating-characters
//
//  Find the length of the longest substring of a string that does not
//  repeat characters.
//
//  Joel Rorseth
//  Created on August 31, 2017
//

#include <iostream>
#include <vector>


// Solution
int length_of_longest_substring(std::string s) {
    std::vector<int> positions(256, -1);
    int length = 0, start = -1;

    // Go through each character in string
    for (int i = 0; i < s.size(); ++i) {

        // If character is a repeat in the current substring eg. in range (start, i)...
        // Set start to one before first letter in new substring
        // We then know that everything after 'start' (our current substring) is unique

        if (positions[s[i]] > start)
            start = positions[s[i]];

        // Map the position of new character to the characters position
        positions[s[i]] = i;

        // Determine if length of range (i, start) is longer than current longest
        length = std::max(length, i - start);
    }

    return length;
}


// Demonstration
int main() {

    std::string a{"aabcefdbag"};
    std::cout << "The longest substring without repeating characters in "
        << a << " is " << length_of_longest_substring(a) << std::endl;
}
