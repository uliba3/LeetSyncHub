# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        ans = []
        que = deque()
        if root is not None:
            que.append(root)
        while len(que) > 0:
            l = len(que)
            sumOfLevel = 0
            for _ in range(l):
                node = que[0]
                sumOfLevel += node.val
                if node.left is not None:
                    que.append(node.left)
                if node.right is not None:
                    que.append(node.right)
                que.popleft()
            ans.append(sumOfLevel/l)
        return ans
