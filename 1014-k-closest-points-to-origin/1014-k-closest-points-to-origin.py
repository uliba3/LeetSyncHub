class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def distance(x, y):
            return x*x + y*y
        distancePoints = []
        for point in points:
            distancePoints.append((distance(point[0], point[1]),point[0], point[1]))
        distancePoints.sort()
        kClosestPoints = []
        for i in range(k):
            kClosestPoints.append([distancePoints[i][1], distancePoints[i][2]])
        return kClosestPoints