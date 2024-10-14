# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        rightSide = []
        if root is None:
            return rightSide
        qCopy = deque()
        qCopy.append(root)
        while len(qCopy) > 0:   
            q = qCopy.copy()
            rightSide.append(q[0].val)
            print(q)
            qCopy = deque()
            while len(q) > 0:
                if q[0].right is not None:
                    qCopy.append(q[0].right)
                    print(q[0].right)
                if q[0].left is not None:
                    qCopy.append(q[0].left)
                    print(q[0].left)
                q.popleft()
        return rightSide
            