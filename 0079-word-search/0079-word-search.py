class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        di = [0,-1,0,1]
        dj = [-1,0,1,0]
        for i in range(len(board)):
            for j in range(len(board[0])):
                c = board[i][j]
                stack = []
                stack.append([i,j,c,set()])
                while stack:
                    xi, yj, char, path = stack.pop()
                    if char != word[len(path)]:
                        continue
                    if len(path) == len(word)-1:
                        return True
                    path.add((xi, yj))
                    for k in range(4):
                        if di[k] + xi < 0 or di[k]+xi >= len(board) or dj[k] + yj < 0 or dj[k] + yj >= len(board[0]):
                            continue
                        if (di[k] + xi, dj[k] + yj) in path:
                            continue
                        stack.append([di[k] + xi, dj[k] + yj, board[di[k] + xi][dj[k] + yj], path.copy()])
        return False

