# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def isValidNode(node: Optional[TreeNode], l: int, r: int) -> bool:
            if l is not None and node.val <= l:
                return False
            if r is not None and node.val >= r:
                return False
            checkLeft = True
            checkRight = True
            if node.left:
                if r is not None:
                    checkLeft = isValidNode(node.left, l , min(r, node.val))
                else:
                    checkLeft = isValidNode(node.left, l, node.val)
            if node.right:
                if l is not None:
                    checkRight = isValidNode(node.right, max(l, node.val) , r)
                else:
                    checkRight = isValidNode(node.right, node.val, r)
            return checkLeft and checkRight
        return isValidNode(root, None, None)