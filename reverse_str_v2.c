// 
// Reverse String
// Reverse a C-String in place.
//

#include <stdio.h>

char * reverse_string(char * start) {

    char * s = start;
    char * end = s;

    // Manually advance pointer to last character
    while (*end) end++;
    end--;

    while (s < end) { 
        // Use XOR to swap 's' and 'end'
        *s ^= *end; *end ^= *s; *s++ ^= *end--; 
    }

    return start;
}


// Demonstration
int main() {

    char a[6] = "Hello";
    printf("%s\n", a);
    printf("%s\n", reverse_string(a));
}
