//
//  Hamming Distance
//  https://leetcode.com/problems/hamming-distance/
//
//  Determine the hamming distance of two integers, defined as the
//  number of positions at which the corresponding bits are different.
//
//  Joel Rorseth
//  Created on May 29, 2017
//

#include <iostream>

// Solution
int hamming_distance(int x, int y) {

    int distance = 0;
    int temp = x ^ y;   // All different bits are set to 1

    while (temp) {

        // Right shift LSB off, shift left to replace it with 0
        // If it was a zero before right shift, no change
        // No change means there was no difference when XOR'ed

        if ( (temp >> 1) << 1 != temp )
            ++distance;
        temp = temp >> 1;
    }

    return distance;
}

// Demonstration
int main() {
    std::cout << "The hamming distance of 1 and 4 is "
        << hamming_distance(1, 4) << std::endl;
}
