//
//  Basic Calculator II
//  https://leetcode.com/problems/basic-calculator-ii
//
//  Implement a basic calculator that can evaluate mathematical
//  expressions including the *, /, + and - operations.
//
//  Eg.  "3+2*2" = 7   ,  " 3+5 / 2 " = 5
//
//  Joel Rorseth
//  Created on July 13, 2017
//

#include <iostream>


// Solution
int calculate(std::string s) {

    int result = 0, current_result = 0;
    char op = '+';


    // Iterate through the string s, skipping whitespace
    for (auto pos = s.find_first_not_of(' '); pos < s.size(); pos = s.find_first_not_of(' ', pos)) {


        if (std::isdigit( s[pos] )) {

            int number = s[pos] - '0';

            // Assemble the full number currently at
            while (++pos < s.size() && std::isdigit( s[pos] ))
                number = (number * 10) + (s[pos] - '0');

            // Update current result: (running result 'op' current number)
            switch (op) {

                case '+': current_result = number; break;
                case '-': current_result = -number; break;
                case '*': current_result = current_result * number; break;
                case '/': current_result = current_result / number; break;
            }


        } else {

            // If + or -, then cache the previous current result in order to come back 
            // to it (after completing higher precedence operation)
            if (s[pos] == '+' || s[pos] == '-') {
                result = result + current_result;
                current_result = 0;
            }

            op = s[pos++];
        }
    }


    return result + current_result;
}


// Demonstration
int main() {

    std::string s{" 3+5 / 2 "};
    std::cout << "\"" << s << "\" = " << calculate(s) << std::endl;
}
