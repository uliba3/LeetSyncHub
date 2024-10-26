class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def recursion(parentheses, left):
            if len(parentheses) == n*2:
                ans.append(parentheses)
            else:
                right = len(parentheses) - left
                if right == left:
                    recursion(parentheses + "(", left + 1)
                elif left == n:
                    recursion(parentheses + ")", left)
                elif right == n:
                    recursion(parentheses + "(", left + 1)
                else:
                    recursion(parentheses + ")", left)
                    recursion(parentheses + "(", left + 1)
                    
        recursion("", 0)
        return ans
        