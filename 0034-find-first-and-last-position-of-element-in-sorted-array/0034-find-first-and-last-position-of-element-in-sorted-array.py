class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        lp = 0
        rp = len(nums) - 1
        while lp<=rp:
            if nums[lp] == target and nums[rp] == target:
                return [lp, rp]
            mid = (lp + rp) // 2
            if nums[mid] > target:
                rp = mid - 1
            elif nums[mid] < target:
                lp = mid + 1
            else:
                if nums[lp] != target:
                    lp += 1
                if nums[rp] != target:
                    rp -= 1
        return [-1, -1]

        