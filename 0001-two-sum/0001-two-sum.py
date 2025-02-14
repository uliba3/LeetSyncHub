class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        # loop through nums and store each element in hashmap
        for i in range(len(nums)):
            hashmap[nums[i]] = i
        # loop again and check if the value exists or not
        for i in range(len(nums)):
            if target - nums[i] in hashmap and hashmap[target-nums[i]] != i:
                return [i, hashmap[target-nums[i]]]