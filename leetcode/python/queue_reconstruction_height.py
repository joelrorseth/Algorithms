#
# Queue Reconstruction by Height
#
# You are given a randomly ordered list of people waiting in a queue. The list
# contains a pair (h,k) for each person, where h is their height, and k is the
# num of ppl standing in front of them that are >= their own height. Since the
# given people are ordered randomly, reconstruct their logical ordering in the
# queue based on how many taller (or equal) people are in front of each person.
#
# Time complexity: O(n^2)
#
# Joel Rorseth
#

def reconstructQueue(people):

    # Sort by descending height, then ascending # taller people ahead
    people.sort(key=lambda pair: (-pair[0], pair[1]))

    # Starting with tallest, insert at position where # taller ppl ahead matches
    # Due to decreasing order of height, insertions will push some taller people
    # back, but they dont care b/c that doesnt violate their # taller ppl ahead.

    queue = []
    for p in people:
        queue.insert(p[1], p)
    return queue


people = [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
print("People: ", people)
print("Queue:  ", reconstructQueue(people))
