#
# Network Time Delay
#
# Given a list of directed edges and weights, as [[u,v,w]], and a starting
# point, how long will it take for all nodes to receive the signal?
#
# We must essentially find the node whose shortest path from start is the
# longest of any other node's path from start.
#
# Joel Rorseth
#

from collections import defaultdict
from heapq import heappush, heappop

# Use Dijkstra
def networkDelayTime(times, N, start):

    # Graph:  u -> { (v, w), ... }, ...
    graph = defaultdict(set)
    for u, v, w in times:
        graph[u].add((v, w))

    vis = set()
    delay = 0

    # Init heap with start node, to track shortest paths
    # IMPORTANT: Dist must be first in pair to sort by that in heap!
    heap = []
    heappush(heap, (0, start))
    while heap:

        cur_weight, cur = heappop(heap)
        if cur not in vis:
            vis.add(cur)

            # Delay will be worst shortest path dist
            delay = max(delay, cur_weight)

            for adj, adj_weight in graph[cur]:
                heappush(heap, (cur_weight + adj_weight, adj))

    # Verify
    if len(vis) != N:
        return -1
    else:
        return delay




# Driver
times = [[1,2,1],[2,1,3]]
print("Times:", times)
print("Starting at 2, delay is", networkDelayTime(times, 2,2))
