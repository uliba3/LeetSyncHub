class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        di = [-1,0,1,0]
        dj = [0,-1,0,1]
        q = deque()
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                g = grid[i][j]
                if g == "0":
                    continue
                count += 1
                q.append([i, j])
                grid[i][j] = "0"
                while q:
                    si = q[0][0]
                    sj = q[0][1]
                    q.popleft()
                    for k in range(4):
                        if si + di[k] < 0 or si + di[k] >= len(grid) or sj + dj[k] < 0 or sj + dj[k] >= len(grid[0]):
                            continue
                        if grid[si+di[k]][sj+dj[k]] == "1":
                            q.append([si+di[k], sj+dj[k]])
                            grid[si+di[k]][sj+dj[k]] = "0"
        return count