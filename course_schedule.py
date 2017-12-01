#
# Course Schedule
#
# Given a list of pairs of courses (a) and their prerequisites (b),
# [a, b], determine if a cycle exists in prerequisites.
#

from collections import defaultdict


def can_finish(numCourses, prerequisites):
    """
    :type numCourses: int
    :type prerequisites: List[List[int]]
    :rtype: bool
    """

    # Create directed graph (DAG in good case)
    adj = defaultdict(set)

    for a, b in prerequisites:
        adj[a].add(b)

    # For each node, we'll track visited nodes while we traverse all
    # related nodes in DFS, looking for already visited nodes (a cycle!)

    visited = set()
    path = set()

    # DFS
    def dfs(node):

        # When we see a repeat node in DFS path, this is a cycle (False)
        if node in path: return False
        if node in visited: return True

        path.add(node)

        for neighbor in adj[node]:
            if not dfs(neighbor): return False

        # DFS complete for node, add to permanantly visited
        path.discard(node)
        visited.add(node)

        return True


    # Do this DFS cycle search for every node
    courses = list(adj.keys())
    return (True if all([dfs(node) for node in courses]) else False)


# Demonstration
def main():

    p = [[1,0],[0,1]]
    print("Prerequisite relationships:", p)
    print("No Cycle?", can_finish(2, p))

main()

