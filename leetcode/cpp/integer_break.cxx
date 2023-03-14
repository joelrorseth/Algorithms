//
// Intger Break
// https://leetcode.com/problems/integer-break/
//
// Determine the maximum number you can obtain by breaking a number n into two or more 
// numbers (that sum to n) and taking their product.
//

#include <iostream>
#include <vector>


// DP Solution
int integer_break(int n) {

    std::vector<int> dp(n+1);
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) 
        for (int j = 1; j < i; ++j) 
            dp[i] = std::max(dp[i], std::max(j, dp[j]) * std::max(i-j, dp[i-j]));


    return dp[n];
}


// Demonstration
int main() {
    
    std::cout << "The maximized product of numbers that sum to 9 is "
        << integer_break(9) << std::endl;
}
