# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def returnOrder(node: Optional[TreeNode]) -> List[TreeNode]:
            tmpList = [node]
            if node.left:
                tmpList = returnOrder(node.left) + tmpList
            if node.right:
                tmpList = tmpList + returnOrder(node.right)
            return tmpList
        orderedList = returnOrder(root)
        return orderedList[k-1].val
        