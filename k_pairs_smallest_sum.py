#
# Find K Pairs With Smallest Sums
#
# Given two integer arrays nums1 and nums2, sorted in ascending order, return
# k pairs (u,v) (where u and v are drawn from nums1 and nums2 respectively)
# that have the smallest sums (u+v).
#
# Joel Rorseth
#

from heapq import heappush, heappop

def kSmallestPairs(nums1, nums2, k):
    if not nums1 or not nums2:
        return []

    heap = []
    for n1 in nums1:
        for n2 in nums2:

            # Push the first k pairs
            if len(heap) < k:
                heappush(heap, (-(n1+n2), n1, n2))

            # Check if current pair sum is < the largest sum in heap, replace
            # Heap stores -sum for maxheap sorting, to easily peek for largest
            else:
                top_sum, _, _ = heap[0]
                if (n1+n2) < -top_sum:
                    heappop(heap)
                    heappush(heap, (-(n1+n2), n1, n2))

    output = []
    while heap:
        _, n1, n2 = heappop(heap)
        output.append([n1,n2])

    return list(reversed(output))





# Driver
n1 = [1,7,11]
n2 = [2,4,6]
print("nums1:", n1, "\nnums1", n2, "\n3 Smallest pairs:", kSmallestPairs(n1,n2,3))
