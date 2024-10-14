# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        que = deque()
        if root is not None:
            que.append(root)
        while len(que) > 0:
            l = len(que)
            levelList = []
            for _ in range(l):
                if que[0].left is not None:
                    que.append(que[0].left)
                if que[0].right is not None:
                    que.append(que[0].right)
                levelList.append(que[0].val)
                que.popleft()
            ans.append(levelList)
        return ans