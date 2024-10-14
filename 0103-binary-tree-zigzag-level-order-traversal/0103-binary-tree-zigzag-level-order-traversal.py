# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque()
        if root:
            q.append(root)
        ans = []
        while q:
            l = len(q)
            level = []
            for _ in range(l):
                if len(ans)%2==1:
                    if q[-1].right:
                        q.appendleft(q[-1].right)
                    if q[-1].left:
                        q.appendleft(q[-1].left)
                    level.append(q[-1].val)
                    q.pop()
                elif len(ans)%2==0:
                    if q[0].left:
                        q.append(q[0].left)
                    if q[0].right:
                        q.append(q[0].right)
                    level.append(q[0].val)
                    q.popleft()
            ans.append(level)
        return ans