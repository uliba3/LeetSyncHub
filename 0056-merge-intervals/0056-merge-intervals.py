class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        newIntervals = []
        intervals.sort()
        currentInterval = intervals[0]
        for interval in intervals:
            if interval[0] <= currentInterval[1]:
                print(interval[0], currentInterval[1])
                currentInterval[0] = min(currentInterval[0], interval[0])
                currentInterval[1] = max(currentInterval[1], interval[1])
                print(currentInterval)
            else:
                newIntervals.append(currentInterval.copy())
                currentInterval = interval.copy()
        newIntervals.append(currentInterval)
        return newIntervals