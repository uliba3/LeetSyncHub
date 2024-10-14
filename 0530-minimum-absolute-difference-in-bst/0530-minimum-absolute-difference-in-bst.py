# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        que = deque()
        ans = 100000
        que.append(root)
        while que:
            l = len(que)
            for _ in range(l):
                if que[0].left:
                    node = que[0].left
                    while node.right:
                        node = node.right
                    ans = min(ans, abs(que[0].val - node.val))
                    que.append(que[0].left)
                if que[0].right:
                    node = que[0].right
                    while node.left:
                        node = node.left
                    ans = min(ans, abs(que[0].val - node.val))
                    que.append(que[0].right)
                que.popleft()
        return ans