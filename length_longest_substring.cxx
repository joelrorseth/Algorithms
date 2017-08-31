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

        // If character is repeat, reset start pos to the repeat
        if (positions[s[i]] > start)
            start = positions[s[i]];

        // Map the position of new character to new character
        positions[s[i]] = i;
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
