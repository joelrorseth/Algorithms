#
# Coin Change 2 (The classic DP coin change problem)
#
# Given a set of coin denominations and a total amount of money,
# determine the number of unique combinations of the coins given
# that make up this amount.
#
# Classic DP problem: Use dp matrix, m*n, where m=#coins and n=amount+1.
# Can actually be reduced to a 1D array of size n, just add previous
# row's value for that index when replacing. dp[i] will be the # of
# unique combinations for $'i', given this current coin (row in matrix)
# and coins previously calculated for.
#
# Time complexity: O(m*n)   , m = # coins
# Space complexity: O(n)    , n = amount + 1
#
# Joel Rorseth
#

def change(amount, coins):

    # dp[0] is always 1 since only 1 way to make $0
    dp = [0] * (amount+1)
    dp[0] = 1

    for coin in coins:
        for i in range(coin, amount+1):

            # Add # of combinations for this amount using previous rows/coins
            #  PLUS # of combinations summing to this amount - current coin
            dp[i] = dp[i] + dp[i - coin]

    return dp[amount]



# Driver
coins = [1,2,5]
amount = 5
print("Coins: ", coins, " Amount: ", amount)
print("# Unique change combos: ", change(amount, coins))
