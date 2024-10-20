class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.matrix = matrix.copy()
        self.sumMatrix = matrix.copy()
        self.sumMatrix[0][0] = matrix[0][0]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i == 0 and j == 0:
                    #print(f"i:{i} j:{j} self.matrix[i][j]:{self.matrix[i][j]} self.sumMatrix[i][j]:{self.sumMatrix[i][j]}")
                    continue
                if i == 0:
                    self.sumMatrix[i][j] = self.sumMatrix[i][j-1] + self.matrix[i][j]
                    #print(f"i:{i} j:{j} self.matrix[i][j]:{self.matrix[i][j]} self.sumMatrix[i][j-1]:{self.sumMatrix[i][j-1]} self.sumMatrix[i][j]:{self.sumMatrix[i][j]}")
                elif j == 0:
                    self.sumMatrix[i][j] = self.sumMatrix[i-1][j] + self.matrix[i][j]
                    #print(f"i:{i} j:{j} self.matrix[i][j]:{self.matrix[i][j]} self.sumMatrix[i-1][j]:{self.sumMatrix[i-1][j]} self.sumMatrix[i][j]:{self.sumMatrix[i][j]}")
                else:
                    self.sumMatrix[i][j] = self.matrix[i][j] + self.sumMatrix[i-1][j] + self.sumMatrix[i][j-1] - self.sumMatrix[i-1][j-1]
                    #print(f"i:{i} j:{j} self.matrix[i][j]:{self.matrix[i][j]} self.sumMatrix[i-1][j]:{self.sumMatrix[i-1][j]} self.sumMatrix[i][j-1]:{self.sumMatrix[i][j-1]} self.sumMatrix[i][j]:{self.sumMatrix[i][j]}")
        #print(self.sumMatrix)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        if col1 == 0 and row1 == 0:
            return self.sumMatrix[row2][col2]
        elif col1 == 0:
            return self.sumMatrix[row2][col2] - self.sumMatrix[row1-1][col2]
        elif row1 == 0:
            return self.sumMatrix[row2][col2] - self.sumMatrix[row2][col1-1]
        else:
            return self.sumMatrix[row2][col2] - self.sumMatrix[row2][col1-1] - self.sumMatrix[row1-1][col2] + self.sumMatrix[row1-1][col1-1]

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)