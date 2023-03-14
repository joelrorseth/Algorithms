#
# 3Sum
#
# Given a list of integers, find all unique triplets that sum to a given sum.
#
# Note: This is a pretty common interview question
# Note 2: This solution uses the same idea (taking the complement) as 2Sum
#

def three_sum(nums, target):
    
    # Optimization check
    if not nums: return []
        
    # Optimization to pass Leetcode runtime restriction
    #counter = Counter(nums)
    #if len(counter.keys()) == 1 and counter[nums[0]] >= 3 and counter.keys()[0] == 0 :
    #    return [[nums[0], nums[1], nums[2]]]
        
    res = set()
        
    # Sort numbers - O(n log n)
    nums.sort()
        
    # Take each number as a first element is a possible pair
    for i in range(len(nums) - 2):
            
        # Calculate the complement for remaining two elements to sum to
        complement = target - nums[i]
            
        # Make pointers for second and third potential tuple elements
        # Start them at the start and end of range of elements after index i
            
        j = i + 1
        k = len(nums) - 1
            
        # Test numbers at indicies i, j and k for sum
        # Move j and k depending on total to try to get closer to target
            
        while j < k:
            
            if nums[j] + nums[k] == complement:
                res.add((nums[i], nums[j], nums[k]))
                k -= 1
                
            elif nums[j] + nums[k] > complement:
                k -= 1
            else:
                j += 1
    
    # Transform list of tuples into list of lists (we needed set for uniqueness)
    to_list = [list(tup) for tup in res]
    return to_list


def main():
    input = [3,5,16,2,17,9,1,11,13,6,0]
    target = 10

    print(input)
    print("All unique triplets that sum to 10:")
    print(three_sum(input, target))


main()
