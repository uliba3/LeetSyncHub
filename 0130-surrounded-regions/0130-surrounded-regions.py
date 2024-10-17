class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def bfs(i, j) -> None:
            nonlocal board
            di = [-1,0,1,0]
            dj = [0,-1,0,1]
            q = deque()
            q.append([i, j])
            board[i][j] = "Y"
            while q:
                bi = q[0][0]
                bj = q[0][1]
                q.popleft()
                for k in range(4):
                    if bi+di[k] < 0 or bi+di[k] >= len(board) or bj+dj[k] < 0 or bj+dj[k] >= len(board[0]):
                        continue
                    if board[bi+di[k]][bj+dj[k]] == "O":
                        q.append([bi+di[k], bj+dj[k]])
                        board[bi+di[k]][bj+dj[k]] = "Y"
        for i in range(len(board)):
            for j in range(len(board[0])):
                if i == 0 or i == len(board)-1 or j == 0 or j == len(board[0])-1:
                    if board[i][j] == "O":
                        bfs(i, j)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == "O":
                    board[i][j] = "X"
                if board[i][j] == "Y":
                    board[i][j] = "O"