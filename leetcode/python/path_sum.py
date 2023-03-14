#
# Path Sum
#
# Given a binary tree and a sum, determine if the tree has a
# root-to-leaf path such that adding up all the values along
# the path equals the given sum.
#

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# Solution
def hasPathSum(root, sum):

    if not root:
         return False

    # Can only return true when sum is reached at a leaf node
    if not root.left and not root.right and root.val == sum:
        return True

    sum -= root.val

    # Check left and right node (paths)
    left = hasPathSum(root.left, sum)
    right = hasPathSum(root.right, sum)

    return left or right


# Demonstration
def main():
    root = TreeNode(1)
    l = TreeNode(2)
    r = TreeNode(5)
    ll = TreeNode(3)
    lr = TreeNode(4)

    root.left = l
    root.right = r
    l.left = ll
    l.right = lr

    print(hasPathSum(root, 7))


main()
