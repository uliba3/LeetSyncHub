import heapq

class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        p1, p2 = 0, 0
        pairs = []
        heap = [[nums1[p1] + nums2[p2], p1, p2]]
        setpp = {(p1, p2)}
        heapq.heapify(heap)
        for i in range(k):
            sumpp, p1, p2 = heapq.heappop(heap)
            pairs.append([nums1[p1], nums2[p2]])
            if p1 + 1 < len(nums1) and (p1 + 1, p2) not in setpp:
                heapq.heappush(heap, [nums1[p1+1] + nums2[p2], p1+1, p2])
                setpp.add((p1 + 1, p2))
            if p2 + 1 < len(nums2) and (p1, p2 + 1) not in setpp:
                heapq.heappush(heap, [nums1[p1] + nums2[p2+1], p1, p2+1])
                setpp.add((p1, p2 + 1))
        return pairs