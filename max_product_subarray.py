#
# Maximum Product Subarray
#
# Given an array of integers, find the contiguous, non-empty subarray
# which maximizes its product.
#
# Joel Rorseth
#

def maxProduct(nums):

    largest = max_here = min_here = nums[0]

    # Modified Kadane's DP algo for maximum subarray
    # Maintain min_here, in case a neg min_here meets another neg num

    for n in nums[1:]:
        temp_max_here = max_here
        max_here = max(max_here * n, min_here * n, n)
        min_here = min(temp_max_here * n, min_here * n, n)
        largest = max(largest, max_here)

    return largest


# Driver
a = [2,3,-2,4]
b = [-2,0,-1]
print(a, " ==> ",  maxProduct(a))
print(b, " ==> ", maxProduct(b))
