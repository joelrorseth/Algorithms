#
# Binary Tree Zigzag Level Order Traversal
#
# Given a binary tree, perform level order traversal such that the first level
# (root) is traversed left to right, second is right to left, then alternate
# for remaining levels.
#
# Joel Rorseth
#

from collections import deque

# Definition for a binary tree node.
 class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None



# Solution
def zigzagLevelOrder(root):
    if not root:
        return []

    level_count = 0
    level = deque([root])
    trav = []

    while level: # For each level
        temp_level = []
        for i in range(len(level)): # For each node in level

            node = level.popleft()
            temp_level.append(node.val)

            if node.left:
                level.append(node.left)
            if node.right:
                level.append(node.right)

        # Odd levels must be reversed
        if level_count % 2 == 1:
            temp_level.reverse()

        trav.append(temp_level)
        level_count += 1

    return trav

