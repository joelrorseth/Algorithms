//
//  Valid Parentheses
//  https://leetcode.com/problems/valid-parentheses/
//
//  Determine if a string is a valid sequence of parentheses
//
//  Joel Rorseth
//  Created on June 27, 2017
//

#include <iostream>
#include <stack>


// Solution
bool is_valid(std::string s) {

    std::stack<char> brackets{};

    for (char & ch: s) {

        switch (ch) {
            case '{':
            case '(':
            case '[': brackets.push(ch); break;
            case '}': if (brackets.empty() || brackets.top() != '{') return false; else { brackets.pop(); } break;
            case ')': if (brackets.empty() || brackets.top() != '(') return false; else { brackets.pop(); } break;
            case ']': if (brackets.empty() || brackets.top() != '[') return false; else { brackets.pop(); } break;
            default: break;
        }
    }

    return brackets.empty();
}

int main() {
    
    std::cout << "Given \"(([]{()}))\", is_valid returns " <<
        (is_valid("(([]{()}))") ? "true" : "false") << std::endl;
}
