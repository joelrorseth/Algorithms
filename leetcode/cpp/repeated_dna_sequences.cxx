//
//  Repeated DNA Sequences
//  https://leetcode.com/problems/repeated-dna-sequences
//  
//  Given a DNA string containing a series of nucleotides abbreviated
//  using only A, C, G and T,  find all the 10-letter-long sequences 
//  (substrings) that occur more than once in the DNA molecule. 
//
//  Joel Rorseth
//  Created on June 14, 2017
//

#include <iostream>
#include <unordered_map>
#include <vector>

// Solution
std::vector<std::string> find_repeated_dna_sequences(std::string s) {
    std::unordered_map<int, int> m;
    std::vector<std::string> repeated;

    // Represent A,C,G,T (0x41, 0x43, 0x47, 0x54) each w/ 3 bits, so 
    // we can store all 30 bytes (3*10) in one 4 byte (32 bits) int. Thus,
    // 0x3FFFFFFF = 0011 1111 1111 1111 1111 1111 1111 1111.
    // (s[i] & 7) gets the last digit which is just the last 3 bits

    total bits of int is 32, there are 2 left, we use 0x3FFFFFFF to remove the leftmost 2 bits.

    for (int t = 0, i = 0; i < s.size(); i++)
        if (m[t = t << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
            repeated.push_back(s.substr(i - 9, 10));
    return repeated;
}


// Solution
int main() {

    std::string s{"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"};
    
    std::cout << "DNA Molecule: " << s << "\nRepeated sequences: {";
    for (auto repeat: find_repeated_dna_sequences(s))
        std::cout << ' ' << repeat << ',';
    std::cout << '}' << std::endl;
}
