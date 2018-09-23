#
# Clone Graph
#
# Given the head node of an undirected graph, return a deep copy (clone)
# of the graph. Cycles and self-loops may be present.
#
# Joel Rorseth
#

from collections import defaultdict

# Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []


class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):

        self.lookup = defaultdict(UndirectedGraphNode)
        return self.clone(node)

    def clone(self, node):
        if not node:
            return None

        # Lookup acts as a sort of visited set, avoid recursing for this again
        # Links to existing node created for new graph

        if node.label in self.lookup:
            return self.lookup[node.label]

        _clone = UndirectedGraphNode(node.label)
        self.lookup[node.label] = _clone

        # DFS thru all neighbors
        for neighbor in node.neighbors:
            _clone.neighbors.append(self.clone(neighbor))

        return _clone
