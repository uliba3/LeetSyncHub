class Solution:
    def findMin(self, nums: List[int]) -> int:
        lp = 0
        rp = len(nums) - 1
        while lp <= rp:
            mid = (lp + rp) // 2
            if nums[lp] < nums[rp]:
                return nums[lp]
            elif nums[lp] > nums[rp]:
                if nums[mid] <= nums[rp]:
                    if nums[mid - 1] < nums[mid]:
                        rp = mid - 1
                    else:
                        return nums[mid]
                elif nums[rp] < nums[mid] and nums[mid] < nums[lp]:
                    lp = mid + 1
                elif nums[mid] >= nums[lp]:
                    lp = mid + 1
            else:
                return nums[mid]
        return nums[mid]