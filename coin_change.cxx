//
// Coin Change
// https://leetcode.com/problems/coin-change/
//
// Given a number of different coin denominations and a target total, determine the fewest number
// of coins required to equal the total. You can only use coins of given denominations.
//

#include <iostream>
#include <vector>


// Solution (Bottom up DP)
int coin_change(std::vector<int> & coins, int amount) {
    
    // Create DP cache for each possible remainder from 'amount'
    int max = amount + 1;
    std::vector<int> dp(amount+1, amount+1);
    
    // 0 is absolute minimum number of coins to total to 0
    dp[0] = 0;
    
    // For each possible remainder (change), test each coin to be fewest number of coins
    for (int remainder = 1; remainder <= amount; ++remainder)
        for (const auto denomination: coins)
            if (denomination <= remainder)
                dp[remainder] = std::min(dp[remainder], dp[remainder - denomination] + 1);
    
    return dp[amount] > amount ? -1 : dp[amount];
}


// Demonstration
int main() {
    
    std::vector<int> coins{1, 3, 5};
    int amount = 20;
    
    std::cout << "The fewest number of coins using denominations of 1, 3 and 5 to total 20 is "
    << coin_change(coins, amount) << std::endl;
}
