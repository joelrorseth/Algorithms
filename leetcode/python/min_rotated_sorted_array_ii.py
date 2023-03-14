#
# Find Minimum in Rotated Sorted Array II
#
# Given an array of integers in ascending sorted order, that have been rotated
# about an unknown pivot, determine the minimum element. Array may contain
# duplicates.
#
# Solution: Use modified binary search
# Time complexity: O(lg n)
#
# Joel Rorseth
#

def findMin(nums):

    low = 0
    high = len(nums) - 1

    # Modified binary search should find point of rotation
    while low < high:

        # Adjusted midpoint finds mid between two points
        mid = low + (high - low) // 2

        # Look left and right to check if either side is ordered wrong
        if nums[low] > nums[mid]:
            high = mid

        elif nums[mid] > nums[high]:
            low = mid + 1

        else:
            high -= 1

    return nums[low]




# Driver
array = [4,5,6,7,0,1,2]
print("Given", array, ", min is", findMin(array))
