class Solution:
    def totalNQueens(self, n: int) -> int:
        ans = 0
        def recursion(queens):
            nonlocal ans
            print(f"queens: {queens}")
            if len(queens) == n:
                ans += 1
            else:
                j = len(queens)
                for i in range(n):
                    isValid = True
                    for queen in queens:
                        if queen[0] == i or queen[1] == j or abs(queen[0] - i) == abs(queen[1] - j):
                            isValid = False
                    if isValid:
                        recursion(queens + [[i, j]])
        recursion([])
        return ans