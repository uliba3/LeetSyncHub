class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def recursion(preNums):
            if len(preNums) == len(nums):
                ans.append(preNums)
            else:
                for num in nums:
                    if num not in preNums:
                        recursion(preNums + [num])
        recursion([])
        return ans
        