#
# House Robber
#
# You are a house robber. You must rob a street of houses, each worth
# a given amount of money. If two adjacent houses are robbed, the police
# will be called. Given an array representing the amounts in each side by
# side house, determine the max amount you can steal without police.
#
# Joel Rorseth
#

def rob(nums):

    two_back, now = 0, 0
    for n in nums:

        # Either rob this house (+ amount taken at two houses back), or
        # take the running cut from prev house and skip this one

        one_back = now
        now = max(n + two_back, one_back)
        two_back = one_back

    return now


# Driver
houses = [2,7,9,3,1]
print(houses)
print(rob(houses))
