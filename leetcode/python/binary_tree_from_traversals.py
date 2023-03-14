#
# Construct Binary Tree From Inorder & Postorder Traversal
# Given an inorder and postorder traversal of a binary tree, reconstruct it.

# Solution is easier than you'd expect. The root is the last element of the
# preorder array. Take it. All elements to left/right of that value in preorder
# are in left/right subtree of that root! Recurse right first, which last
# element will again be root. Eventually after right recursion terminates,
# the left path will recurse and last node of postorder is left's root.
#
# Time (and space) complexity: O(n)
#
# Joel Rorseth
#

def buildTree(inorder, postorder):

    if not inorder or not postorder:
        return None

    root = TreeNode(postorder.pop())

    # Find index of root in inorder trav, recurse left and right sides
    mid = inorder.index(root.val)

    # Go RIGHT then left!!
    # This allows for rightmost tree roots to be extracted from end of postorder
    # The pop operation leaves the correct root val at last idx when eventually recurses left
    root.right = buildTree(inorder[(mid+1):], postorder)
    root.left = buildTree(inorder[:mid], postorder)

    return root

