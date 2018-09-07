#
# Unique Paths
#
# Given an MxN grid, a robot is placed in top left at (0,0). It can only
# move down and to the right. Determine how many unique paths it can take
# to reach the bottom right corner.
#
# Joel Rorseth
#

def uniquePaths(m, n):

    dp = [1 for r in range(n)]

    for _ in range(1,m):        # Skip first row, all 1's
        for j in range(1,n):    # Skip idx 0, always 1
            dp[j] = dp[j-1] + dp[j]

    return dp[-1]



print("%d x %d grid => %d unique paths" % (7,3, uniquePaths(7,3)))
