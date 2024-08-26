class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<int, bool> isRow;
        map<int, bool> isCol;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    isRow[i] = true;
                    isCol[j] = false;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isRow.contains(i) || isCol.contains(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};