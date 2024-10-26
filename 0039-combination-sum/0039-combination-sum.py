class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        def recursion(candidateNums, targetNum):
            print(f"candidateNums:{candidateNums} targetNum:{targetNum}")
            if targetNum == 0:
                ans.append(candidateNums[1:])
            else:
                lastNum = candidateNums[-1]
                for num in candidates:
                    if num > targetNum or num < lastNum:
                        continue
                    recursion(candidateNums + [num], targetNum - num)
        recursion([0], target)
        return ans
        