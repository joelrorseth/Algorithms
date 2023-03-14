#
# Keys and Rooms
#
# You are given an array room of size N, representing N rooms numbered 0..N-1.
# Each room[i] is an array of keys, labelled 0..N-1, which unlock the
# corresponding room. If you start at room 0 (unlocked), determine if you can
# unlock every room, given that you can walk back and forth freely.
#
# Joel Rorseth
#

from collections import defaultdict

def canVisitAllRooms(rooms):

    graph = defaultdict(set)
    n = len(rooms)

    for i, keys in enumerate(rooms):
        for key in keys:
            graph[i].add(key)

    path = set()
    path.add(0)
    return canVisit(0, graph, n, path)


# DFS will attempt to visit all rooms using keys (adj nodes)
# Any room visited cannot be "unvisited", must visit all to return TRUE
def canVisit(cur, graph, n, path):

    if len(path) == n:
        return True

    for adj in graph[cur]:
        if adj not in path:
            path.add(adj)

            if canVisit(adj, graph, n, path):
                return True

    return False





# Driver
rooms = [[1],[2],[3],[]]
print("Rooms:", rooms)
print("Can unlock all rooms?", canVisitAllRooms(rooms))
