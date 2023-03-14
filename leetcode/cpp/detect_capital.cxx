//
//  Detect Capital
//  https://leetcode.com/problems/detect-capital/
//  
//  Determine if a word if capitialized correctly. By definition,
//  can only be all upper case, all lower case, or first character
//  upper followed by all lower.
//
//  Joel Rorseth
//  Created on May 26, 2017
//

#include <iostream>

// Helper
bool is_cap(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

// Solution
bool detect_capital_use(std::string word) {

    bool c0 = is_cap(word[0]);
    bool c1 = is_cap(word[1]);

    bool all_caps = (c0 && c1);
    bool all_lower = !all_caps;

    if (!c0 && c1)
        return false;

    // Checking char by char is much more efficient
    for (int i = 2; i < word.length(); ++i) {
        int w = word[i];

        if ((all_lower && is_cap(w)) || (all_caps && !is_cap(w)))
            return false;
    }

    return true;

    // Regex solution (Slow)
    //std::regex re{"([A-Z]+)|([A-Z][a-z]+)|([a-z]+)"};
    //return (regex_match(word, re));
}

// Demonstration
int main() {

    std::cout << "detect_capital_use(HeLlo) = " 
        << (detect_capital_use("HeLlo") ? "true" : "false") << std::endl;
}
