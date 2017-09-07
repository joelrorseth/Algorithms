//
//  Reverse Words in a String
//  https://leetcode.com/problems/reverse-words-in-a-string
//
//  Given a string of words, return a new string reversed word by word.
//
//  Joel Rorseth
//  Created on September 7, 2017
//

#include <iostream>

// In-place word reversal (by reference)
void reverse_word(std::string & s, int b, int e) {
    char temp;
    
    // Swap two chars at a time tarting at each
    // end and moving inwards
    
    while (b<e) {
        temp = s[b];
        s[b++] = s[e];
        s[e--] = temp;
    }
}

// Solution --  O(n) time, O(1) space
void reverse_words(std::string & s) {
    int i=0, l=0, j=0, wordcount=0;
    int len = s.size();
    
    // Essentially iterate thru each word in this loop
    while (true) {
        
        // Move i to first non space character
        while (i<len && s[i] == ' ') i++;
        
        // If end of string has been reached, break
        if (i == len) break;
        
        // If words have been read, insert space at s[j]
        if (wordcount) s[j++] = ' ';
        
        // Cache j into l
        l = j;
        
        // Copy word starting at i to position starting at j
        while (i<len && s[i] != ' ') {
            s[j++] = s[i++];
        }
        
        // Reverse the word just copied
        reverse_word(s, l, j-1);
        ++wordcount;
    }
    
    // Reverse the entire string and trim it for final answer
    s.resize(j);
    reverse_word(s, 0, j-1);
}


// Demonstration
int main() {
    
    std::string a{"This is a string"};
    std::cout << "Original string:  " << a << '\n';
    
    reverse_words(a);
    std::cout << "Reversed by word:  " << a << '\n';
}
