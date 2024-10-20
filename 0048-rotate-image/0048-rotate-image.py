class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i > j:
                    continue
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        print(matrix)
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if j >= len(matrix[0])/2:
                    continue
                matrix[i][j], matrix[i][len(matrix[0])-j-1] = matrix[i][len(matrix[0])-j-1], matrix[i][j]
        