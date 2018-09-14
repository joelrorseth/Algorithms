#
# Combination Sum III
#
# Find all combinations of K numbers that sum to an integer N, given
# that only integers 1,2...9 may be used. Each combination should
# be a sorted, unique set of numbers.
#
# Joel Rorseth
#


def combinationSum3(k, n):
    combs = []
    combSum(k, 1, 9, [], n, combs)
    return combs


# Backtracking solution tries all combinations until it deemed fit/unfit
def combSum(k, start, end, cur_nums, sum_remainder, combs):

    # If k numbers present, and sum == N, add combination to combs
    if k == 0 and sum_remainder == 0:
        combs.append(cur_nums)

    # If we still need to try numbers...
    if k >= 0 and sum_remainder > 0:
        for i in range(start, end+1):
            combSum(k-1, i+1, end, cur_nums + [i], sum_remainder - i, combs)



# Driver
print("Combinations of %d numbers that sum to %d:" % (3,9))
print(combinationSum3(3,9))
