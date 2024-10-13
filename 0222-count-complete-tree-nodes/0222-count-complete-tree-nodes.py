# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        count = 0
        height = 0
        cur = root
        while cur:
            cur = cur.left
            height += 1
        found = False
        def checkNode(node: Optional[TreeNode], h) -> int:
            nonlocal count
            nonlocal found
            if h > 1:
                checkNode(node.right, h-1)
                if found:
                    return
                checkNode(node.left, h-1)
            if h==1 and node:
                found = True
                return
            elif h==1 and not node:
                count += 1
        checkNode(root, height)
        return 2**height-count-1