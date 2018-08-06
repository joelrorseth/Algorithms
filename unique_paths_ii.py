#
# Unique Paths II
# Given an m x n grid, where 1 represents an obstacle, and 0 a free
# space, determine the number of unique paths from the top left
# corner to the bottom right. Only down or rightwards moves allowed.
#
# Joel Rorseth
#


# Time complexity: O(mn)
# Space complexity: O(n)

def uniquePathsWithObstacles(obstacleGrid):

    # Use 1D dp array to maintain # paths coming from row above current
    width = len(obstacleGrid[0])
    dp_row = [0] * width
    dp_row[0] = 1

    for i in range(len(obstacleGrid)):
        for j in range(width):

            # 0 paths to any obstacle
            if obstacleGrid[i][j] == 1:
                dp_row[j] = 0

            # Add # paths from above (dp[j]) to # paths left
            elif j > 0:
                dp_row[j] = dp_row[j] + dp_row[j-1]

    return dp_row[-1]


# Driver
grid = [[0,0,0],[0,1,0],[0,0,0]]
for row in grid:
    print(row)
print("# Unique Paths: %d" % uniquePathsWithObstacles(grid))
