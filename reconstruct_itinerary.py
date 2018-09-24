#
# Reconstruct Itinerary
#
# Given a list of airplane tickets represented as pairs of [from,to] departure
# and arrival airports, reconstruct the itinerary in order. The itinerary
# begins at JFK, and when multiple itineraries are valid, the one with the
# smallest lexical ordering is the valid one.
#
# Joel Rorseth
#

from collections import defaultdict, deque

# This problem is essentially the Build Order problem
# Just use topological sort, but DFS thru cities in sorted order

def findItinerary(tickets):

    graph = defaultdict(deque)
    for src, dest in sorted(tickets):
        graph[src].appendleft(dest)

    order = deque()
    findIt("JFK", graph, order)
    return list(order)


def findIt(city, graph, order):
    # Recurse to each adj city, then remove adj to unlink 'dependency'
    while graph[city]:
        findIt(graph[city].pop(), graph, order)
    order.appendleft(city)





# Driver
t = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
print("Tickets:", t)
print("Reconstructed Itinerary:", findItinerary(t))
