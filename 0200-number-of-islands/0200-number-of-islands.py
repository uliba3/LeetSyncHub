mi = [1,-1,0,0]
mj = [0,0,1,-1]

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # number of islands
        counter = 0
        # queue for tracking which grid to check
        q = deque()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                # if grid is water or visited land
                if grid[i][j] == "0" or grid[i][j] == "2":
                    continue
                else: # if grid is land
                    counter += 1
                    q.append([i, j])
                    while len(q) > 0:
                        x, y = q.popleft()
                        if grid[x][y] == "1":
                            grid[x][y] = "2"
                            for k in range(4):
                                if x + mi[k] < 0 or x + mi[k]>=len(grid) or y + mj[k] < 0 or y + mj[k]>=len(grid[0]):
                                    continue
                                if grid[x+mi[k]][y+mj[k]] == "0" or grid[x+mi[k]][y+mj[k]] == "2":
                                    continue
                                q.append([x+mi[k], y+mj[k]])        
        return counter
        