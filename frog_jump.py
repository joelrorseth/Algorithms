#
# Frog Jump
#
# A frog is crossing a river by jumping across stones. The positions of the
# stones are given as an array, where there is equal distance between each
# stone. Determine if the frog can cross from first to last stone, given that:
#  - Frog starts at first stone (always pos 0), must jump 1 unit to second stone
#  - Every jump thereafter must be k-1, k or k+1 units
#  - Frog may jump any number of stones ahead, given that it is reachable
#
# Joel Rorseth
#


def canCross(stones):
    if not stones:
        return False
    if len(stones) == 1:
        return True
    if len(stones) == 2:
        return stones[0]==0 and stones[1]==1

    memo = {}
    return cross(1, 1, stones, memo)


def cross(pos, last_k, stones, memo):

    # Base case: Last stone has been reached, return true
    if pos == (len(stones)-1):
        return True

    # Memoize cross-ability for this pos and previous k
    if (pos,last_k) in memo:
        return True if memo[(pos,last_k)] == 1 else False

    next_pos = pos+1
    while next_pos < len(stones) and (stones[next_pos] - stones[pos]) <= (last_k+1):

        # Recurse: Either k-1, k or k+1 jump must work recursively
        for k in [last_k-1, last_k, last_k+1]:
            if (stones[pos] + k) == stones[next_pos]:
                if cross(next_pos, k, stones, memo):
                    memo[(pos, last_k)] = 1
                    return True

        next_pos = next_pos+1

    memo[(pos, last_k)] = 0
    return False






# Driver
stones = [0,1,3,5,6,8,12,17]
print("Stones:", stones)
print("Can cross?", canCross(stones))
