//
//  Permutation Sequence
//  https://leetcode.com/problems/permutation-sequence
//
//  Given an n in [1,9], determine the kth permutation sequence from
//  the sorted set of permutations of the numbers 1 through n. There
//  are n! unique permutations in [1,n], and you must find the kth as it
//  would appear in sorted order.
//
//  Joel Rorseth
//  Created on July 4, 2017
//

#include <iostream>

// Solution
std::string get_permutation(int n, int k) {
    
    int i, j, factorial = 1;
    std::string factorial_sequence(n,'0');
    
    // Calculate factorial of n
    // Make a string with factorial sequence eg. 1234...n
    for (i = 1; i <= n; ++i) {
        factorial *= i;
        factorial_sequence[i-1] += i; // make s become 1234...n
    }
    
    
    for (i = 0, k--; i < n; ++i) {
    
        factorial /= n - i;     // Decrement to factorial of (current n) - 1
        j = i + k / factorial;  // Calculate index of char to put at s[i]
        
        char c = factorial_sequence[j];
        
        // Remove c by shifting to cover up (adjust the right part)
        for(; j > i; --j)
            factorial_sequence[j] = factorial_sequence[j - 1];
    
        k %= factorial;
        factorial_sequence[i] = c;
    }
    
    return factorial_sequence;
}

int main() {

    std::cout << "Given n=4 and k=14, get_permutation(4, 14) is: " <<
        get_permutation(4, 14) << std::endl;
}