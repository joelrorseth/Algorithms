#
# Path Sum II
# Return a list of all paths in a binary tree whose nodes add to a given sum.
#

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# Modified DFS that maintains list of current nodes in traversed path
def pathSum(self, root, s):
    
    # Base case: Null node
    if not root: return []
    
    result = []
        
    # Keep a stack representing each node along current recursive path
    stack = [(root, [root.val])]
        
    while stack:
        cur, val = stack.pop()
            
        # If sum has been found with this path (ending at leaf)
        if not cur.left and not cur.right and sum(val) == s:
            result.append(val)
            
        if cur.right:
            # Add right val to current path list
            stack.append(( cur.right, val + [cur.right.val] ))
            
        if cur.left:
            # Add left val to current path list
            stack.append(( cur.left, val + [cur.left.val] ))
    
    return result
