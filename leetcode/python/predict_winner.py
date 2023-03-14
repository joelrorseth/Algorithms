#
# Predict The Winner
#
# You are given an array of non-negative numbers. Two players, P1 and P2,
# take turns drawing a number from either end of the array, removing it
# and adding it to their score. Each player strategically picks the best
# number. Predict if P1, who goes first, will win with the highest score,
# given the array.
#
# Time complexity: O(n^2)
# Space complexity: O(n^2) for memoization
#
# Joel Rorseth
#

def PredictTheWinner(nums):

    cache = [[None for _ in range(len(nums))] for _ in range(len(nums)) ]
    return predict(0, len(nums)-1, 1, nums, cache) >= 0


def predict(s, e, turn, nums, cache):

    if s == e:
        return nums[s]

    # Memoize the best picks given any subarray
    if cache[s][e]:
        return cache[s][e]

    # Find optimal solution by choosing left or right end number
    left = nums[s] - predict(s+1, e, -turn, nums, cache)
    right = nums[e] - predict(s, e-1, -turn, nums, cache)

    cache[s][e] = max(left, right)
    return cache[s][e]




# Driver
game = [1, 5, 233, 7]
print("Game:", game)
print("Player 1 will win:", PredictTheWinner(game))
