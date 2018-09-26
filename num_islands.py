#
# Number of Islands
#
# Given a 2D grid of 1's (land) and 0's (water), count the number of islands.
# An island is any block of 1's connected horizontally or vertically.
# Assume the grid itself is surrounded by water.
#
# Joel Rorseth
#

def numIslands(grid):

    if not grid:
        return 0

    count = 0
    m = len(grid)
    n = len(grid[0])


    # Given that i,j is part of island, color it '2' and color rest of island
    def recolor(i, j):

        grid[i][j] = "2"
        if i > 0 and grid[i-1][j] == "1":
            recolor(i-1,j)
        if i+1 < m and grid[i+1][j] == "1":
            recolor(i+1,j)
        if j > 0 and grid[i][j-1] == "1":
            recolor(i,j-1)
        if j+1 < n and grid[i][j+1] == "1":
            recolor(i,j+1)

    # Count each island found, color whole island to avoid counting again
    for i in range(m):
        for j in range(n):
            if grid[i][j] == "1":
                recolor(i,j)
                count += 1

    # Uncolor islands
    for i in range(m):
        for j in range(n):
            if grid[i][j] == "2":
                grid[i][j] = "1"

    return count




# Driver
g = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
print('\n'.join(str(row) for row in g))
print("Number of islands: %d" % numIslands(g))
