class Solution:
    def trap(self, height: List[int]) -> int:
        # no negative height
        lWalls, rWalls = [], [0] * len(height)
        leftMaxWall = 0
        rightMaxWall = 0
        for i in range(len(height)):
            leftMaxWall, rightMaxWall = max(height[i], leftMaxWall), max(height[len(height) -i - 1], rightMaxWall)
            lWalls.append(leftMaxWall)
            rWalls[len(height)-i-1] = rightMaxWall
        
        print(lWalls, rWalls)

        water = 0
        for i in range(len(height)):
            wallHeight = min(lWalls[i], rWalls[i])
            if wallHeight > height[i]:
                water += wallHeight - height[i]
        
        return water