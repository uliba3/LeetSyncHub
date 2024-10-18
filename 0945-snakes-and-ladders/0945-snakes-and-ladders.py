class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        graphNum = {}
        n = len(board)
        for i in range(n):
            for j in range(n):
                num = i*n + j +1
                if (num-1)%(n*2) >= n:
                    graphNum[num] = [n-i-1, n-j-1]
                else:
                    graphNum[num] = [n-i-1, j]
        print(f"n:{n}")
        #print(f"graphNum:{graphNum}")
        q = deque()
        q.append([1, 0])
        visited = set()
        minSteps = -1
        while q:
            #print(f"q:{q}")
            curr, steps = q.popleft()
            i, j = graphNum[curr]
            visited.add(curr)
            if board[i][j] != -1:
                curr = board[i][j]
            if curr == n*n:
                minSteps = steps
                break
            for k in range(1, 7):
                if k + curr <= n*n and k + curr not in visited:
                    q.append([k+curr, steps+1])
                    visited.add(k+curr)
        return minSteps
