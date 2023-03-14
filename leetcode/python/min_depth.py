#
# Minimum Depth of Binary Tree
#
# Determine the minimum depth of a binary tree, defined as the
# number of nodes along the shortest path from the root to the
# nearest leaf.
#


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# Perform a breadth first search (BFS)
# This works best when finding shortest paths
def min_depth(root):

    # Edge case: No nodes means path length is 0
    if not root: return 0

    depth = 0
    level = [root]

    while True:
        depth += 1
        new_level = []

        for current in level:

            # If this node is a leaf, return depth now
            if not current.left and not current.right:
                return depth;

            # Add next level children for next while loop iteration (depth+1)
            if current.left:
                new_level.append(current.left)

            if current.right:
                new_level.append(current.right)

        level = new_level

    return -1



def main():
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(4)
    e = TreeNode(5)
    f = TreeNode(6)

    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.left = f

    print(min_depth(a))

main()
