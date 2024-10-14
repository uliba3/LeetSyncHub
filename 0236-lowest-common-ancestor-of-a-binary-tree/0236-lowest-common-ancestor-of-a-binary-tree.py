# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        visitedP = []
        visitedQ = []

        # Helper function to record the path from root to target node
        def markNode(node: 'TreeNode', visited: List['TreeNode']):
            nonlocal visitedP, visitedQ
            if not node:
                return
            visited.append(node)
            if node is p:
                visitedP = visited.copy()
            if node is q:
                visitedQ = visited.copy()
            markNode(node.left, visited.copy())
            markNode(node.right, visited.copy())

        # Traverse and mark the paths for p and q
        markNode(root, [])
        print(len(visitedP))
        print(len(visitedQ))

        # Find the lowest common ancestor by comparing the paths
        min_length = min(len(visitedP), len(visitedQ))
        for i in range(min_length):
            if visitedP[i] != visitedQ[i]:
                return visitedP[i - 1]

        # If all nodes in the shorter path are common, return the last common node
        return visitedP[min_length - 1]