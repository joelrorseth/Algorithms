//
//  Basic Calculator
//  https://leetcode.com/problems/basic-calculator
//
//  Given a string with a valid arithmetic expression, calculate the result.
//  Only addition and subtraction operations will be given, along with valid
//  parentheses.
//
//  Joel Rorseth
//  Created on June 29, 2017
//

#include <iostream>
#include <cctype>
#include <stack>


// Solution
int calculate(std::string s) {

    // This problem assumes only addition / subtraction operations will be given
    // We thus treat any minus sign as a negative, and instead add a negative number

    std::stack<int> numbers, operations;
    int current_num = 0;
    int total = 0;
    int sign = 1;

    for (char c : s) { 
        if (isdigit(c)) 
            current_num = current_num * 10 + (c - '0');

        else {

            // Add current number that has been formed to the total, reset current
            total += sign * current_num;
            current_num = 0;

            // If char is a sign, change the sign multiplier for current number
            if (c == '+') sign = 1;
            if (c == '-') sign = -1;

            // At left bracket, push total onto stack for later
            // When you see ')' later, you will pop this layer's total and add to nested layer's total
            // You can then continue with this layer now that nested layer was added
            if (c == '(') {
                numbers.push(total);
                operations.push(sign);
                total = 0;  // Reset
                sign = 1;   // Reset
            }

            // At closing bracket, add total from previous bracket 'layer' to this total
            if (c == ')' && operations.size()) {
                total = operations.top() * total + numbers.top();
                operations.pop(); 
                numbers.pop();
            }
        }
    }

    total += sign * current_num;
    return total;

}


// Demonstration
int main() {

    std::cout << "The result of calculating \"(1+(4+5+2)-3)+(6+8)\" is "
        << calculate("(1+(4+5+2)-3)+(6+8)") << std::endl;
}
