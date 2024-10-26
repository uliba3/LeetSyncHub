class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        def recursion(nums, remainingK):
            if remainingK == 0:
                ans.append(nums[1:])
            else:
                remainingK -= 1
                for i in range(nums[-1] + 1, n + 1):
                    recursion(nums + [i], remainingK)
        recursion([0], k)
        return ans        