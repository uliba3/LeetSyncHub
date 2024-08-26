class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < (matrix.size()+1)/2; i++){//layer
            for(int j = 0; j < (matrix.size()-1); j++){//jth element in layer
                if(j<i || j>(matrix.size()-i-2)){
                    continue;
                }
                cout << "i" << i << "j" << j << endl;
                swap(matrix[i][j], matrix[matrix.size()-j-1][i]);
                swap(matrix[matrix.size()-j-1][i], matrix[matrix.size()-i-1][matrix.size()-j-1]);
                swap(matrix[matrix.size()-i-1][matrix.size()-j-1], matrix[j][matrix.size()-i-1]);
            }
        }
    }
};