#
# Is Graph Bipartite?
#
# Determine if a graph is bipartite, which is defined as a graph in which we
# can split it's set of nodes into 2 independent subsets A and B such that
# every edge in the graph has one node in A and another in B.
#
# Joel Rorseth
#

from collections import defaultdict

def isBipartite(graph):

    # Each node in bipartite graph can be colored such that no two adjacent
    # nodes are the same color. Try all colorings using backtracking DFS

    color_for = [-1] * len(graph)

    for i in range(len(graph)):
        if color_for[i] == -1 and not findValidColoring(graph, color_for, i, 0):
            return False
    return True


def findValidColoring(graph, color_for, cur_node, color):

    if color_for[cur_node] != -1:
        return color_for[cur_node] == color

    color_for[cur_node] = color

    # Try coloring each adj node the opposite color, see if DFS finds this combo to be valid
    for adj_node in graph[cur_node]:
        if not findValidColoring(graph, color_for, adj_node, 1-color):
            return False

    # Now with this node and color, coloring all adj nodes opposite worked out recursively
    return True





# Driver
graph = [[1,3], [0,2], [1,3], [0,2]]
print("Graph:", graph)
print("Bipartite?", isBipartite(graph))
