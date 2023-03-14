//
//  Counting Bits
//
//  https://leetcode.com/problems/counting-bits/
//  Calculate the number of bits for each number 0 to num
//
//  Joel Rorseth
//  Created on May 31, 2017
//

#include <iostream>
#include <vector>

// Solution
std::vector<int> count_bits(int num) {
    std::vector<int> bits(num+1, 0);

    for (int i = 1; i <= num; i++) 
        bits[i] += bits[i & (i-1)] + 1;

    return bits;
}

int main() {
    std::cout << "count_bits(5) = {";

    for (auto r: count_bits(5))
        std::cout << r << ',';
    std::cout << '}' << std::endl;
}
