#
# Longest Increasing Path in a Matrix
#
# Find the length of the longest increasing path within a matrix, by moving
# only up, down, left, or right. Wrap around is not permitted.
#
# Joel Rorseth
#

# Check if (_i,_j) is okay to move from (i,j)
def validNext(matrix, i, j, _i, _j):
  return (_i<len(matrix) and _j<len(matrix[0]) and _i>=0 and _j>=0 and matrix[_i][_j]>matrix[i][j])
  
# Use DFS to walk each L,R,U,D path recursively and find max increasing length
def dfsPaths(matrix, i, j, dp, dirs):
  if dp[i][j] != 0:
    return dp[i][j]
      
  longest = 0
  for d in dirs:
    _i = i+d[0]
    _j = j+d[1]
          
  if validNext(matrix, i,j, _i,_j):
    length = 1+dfsPaths(matrix, _i, _j, dp, dirs)
    longest = max(longest, length)
    
  dp[i][j] = longest
  return longest
    
# Attempt to backtrack and find best path starting at each element
def longestIncreasingPath(matrix):
    
  if len(matrix)==0:
    return 0
        
  m = len(matrix)
  n = len(matrix[0])
  dirs = [(0,1), (0,-1), (1,0), (-1,0)]
  dp = [[0 for j in range(n)] for i in range(m)]
        
  longest = 0
  for i in range(len(matrix)):
    for j in range(len(matrix[0])):
            
      length = 1+dfsPaths(matrix, i, j, dp, dirs)
      longest = max(longest, length)
              
  return longest


def main():
  matrix = [[9,9,4],[6,6,8],[2,1,1]]
  print(matrix)
  print("Longest increasing path length: %d\n" % longestIncreasingPath(matrix))
main()
