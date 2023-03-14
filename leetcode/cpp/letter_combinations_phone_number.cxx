//
//  Letter Combinations of a Phone Number
//  https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//  
//  Given a phone number (sequence of digits) that maps to respective
//  letters on a standard phone, determine all letter combinations that
//  are possible when entered sequentially.
//
//  Joel Rorseth
//  Created on June 20, 2017
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Solution
std::vector<std::string> letter_combinations(std::string digits) {

    if (digits.empty()) return std::vector<std::string>{};

    std::vector<std::string> result{""};
    std::vector<std::string> const keys{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


    // Loop through every digit, expand upon combos from previous digits one digit at a time
    for (int i = 0; i < digits.size(); ++i) {

        int num = digits[i] - '0';
        if(num < 0 || num > 9) break;

        const std::string & key_chars = keys[num];
        if(key_chars.empty()) continue;

        std::vector<std::string> updated_result;

        // Combine each new character in this key with each previous char combo
        // The n^2 loop allows every previous combo to append each new char in a new combo
        for(int j = 0 ; j < key_chars.size() ; ++j) 
            for(int k = 0 ; k < result.size() ; ++k) 
                updated_result.push_back(result[k] + key_chars[j]);


        // Update the most current char combos
        result.swap(updated_result);
    }

    return result;
}


// Demonstration
int main() {

    std::cout << "On a phone, all letter combinations for 4756 are:\n";
    for (auto combo: letter_combinations("4756"))
        std::cout << combo << ',' << ' ';
    std::cout << std::endl;
}
