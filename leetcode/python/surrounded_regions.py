#
# Surrounded Regions
#
# Given a 2D board containing X's and O's, flip all regions of O's that are
# completely surrounded by X's to O's.
#
# Solution is quite simple. Simply look for O's along border, and mark any
# O regions starting there with M. All remaining (non-border-originating)
# regions are flippable. Flip those to X, and the M's back to O's.
#
# Time: O(n*m)
# Joel Rorseth
#

def solve(board):
    if not board or len(board)==0:
        return

    n = len(board)
    m = len(board[0])

    def mark(i, j):
        if 0<=i<n and 0<=j<m and board[i][j] == 'O':
            board[i][j] = 'M'
            mark(i-1,j)
            mark(i+1,j)
            mark(i,j-1)
            mark(i,j+1)

    # Mark all 0 regions originating from border as unflippable
    for i in range(n):
        mark(i, 0)
        mark(i, m-1)

    for j in range(m):
        mark(0, j)
        mark(n-1, j)

    # Any remaining (non-border) O's can be flipped
    for i in range(n):
        for j in range(m):
            if board[i][j] == 'O':
                board[i][j] = 'X'
            if board[i][j] == 'M':
                board[i][j] = 'O'





# Driver
b = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
print("Board:")
print("\n".join(str(row) for row in b))
solve(b)
print("\nFlipped:")
print("\n".join(str(row) for row in b))
