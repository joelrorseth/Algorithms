//
//  Lexicographical Numbers
//  https://leetcode.com/problems/lexicographical-numbers
//
//  Given a range 1 to n, sort all numbers in said range lexicographically.
//  Eg. n=13 => 1,10,11,12,13,2,3,4,5,6,7,8,9
//
//  Joel Rorseth
//  Created on June 28, 2017
//

#include <iostream>
#include <vector>


// Solution
std::vector<int> lexical_order(int n) {
    std::vector<int> ordered(n, 0);
    int current = 1;

    for(int i = 0; i < n; ++i) {
        ordered[i] = current;

        // If current with 0 appended is in [1,n], change current to that
        // This attempts to move one decimal place right and test if those are in range
        if (current * 10 <= n)
            current *= 10;

        else {

            // Trim off rightmost zero if current is greater than n
            // This will stop iteration thru rightmost decimal place
            // Eg. If current=305 and n=305, current goes back to 30

            if (current >= n)
                current /= 10;

            // Always increase the number at the current rightmost decimal place
            ++current;

            // Trim off all rightmost zeros of current
            while (current % 10 == 0)
                current /= 10;
        }
    }

    return ordered;
}

// Demonstration
int main() {

    std::cout << "Sorted lexicographically, numbers 1 through 13 would appear as: i\n";
    for (auto number: lexical_order(13))
        std::cout << number << ',' << ' ';
    std::cout << std::endl;
}
