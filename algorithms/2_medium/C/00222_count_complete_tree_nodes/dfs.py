def dfs_h_right(curr):
    if curr == None: return 0

    return 1 + dfs_h_right(curr.right)

def dfs_h_left(curr):
    if curr == None: return 0

    return 1 + dfs_h_left(curr.left)

def dfs(curr):
    h_left = dfs_h_left(curr)
    h_right = dfs_h_right(curr)

    if h_right == h_left:
        return (1 << h_left) - 1
    else:
        return 1 + dfs(curr.left) +  dfs(curr.right)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        return dfs(root)
