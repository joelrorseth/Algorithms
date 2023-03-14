//
// String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/
//
// Write a function that converts a string representing an integer
// into an actual integer. You must account for an extra leading
// whitespace, +/- sign, integer overflow, and illegal characters.
//

#include <stdio.h>
#include <limits.h>


int my_atoi(char* str) {

    char * c = str;
    int result = 0;
    int sign = 1;

    // Skip over whitespace, note any signs
    while (*c == ' ') { c++; }
    if (*c == '-' || *c == '+') { sign = (*c == '-' ? -1 : 1); c++; }


    // While character is a valid number
    while (*c >= '0' && *c <= '9') {

        // Check for overflow
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && *c - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }

        // Convert char to digit and add to result
        int d = *c++ - '0';
        result = result * 10 + d;
    }

    return result * sign;
}


// Demonstration
int main() {

    char n1[5] = "1234";
    char n2[8] = "   -543";
    char n3[6] = "  -4f";

    printf("Input:\n%s\n%s\n%s\n", n1, n2, n3);
    printf("\nConverted:\n%d\n%d\n%d\n", my_atoi(n1), my_atoi(n2), my_atoi(n3));
}
