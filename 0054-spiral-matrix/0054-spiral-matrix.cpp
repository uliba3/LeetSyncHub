class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns

        vector<int> iDirection = {1, 0, -1, 0};
        vector<int> jDirection = {0, 1, 0, -1};
        
        vector<vector<bool>> checker(m, vector<bool>(n, false)); // Initialize checker
        
        int i = 0; // Starting col index
        int j = 0; // Starting row index
        int direction = 0; // Direction index (0 = right, 1 = down, 2 = left, 3 = up)
        spiral.push_back(matrix[j][i]);
        checker[i][j] = true;
        cout << "i" << i << "j" << j << endl;
        while(true){
            if(i+iDirection[direction]>=n||
            j+jDirection[direction]>=m||
            i+iDirection[direction]<0||
            j+jDirection[direction]<0||
            checker[j+jDirection[direction]][i+iDirection[direction]]){
                direction++;
                direction = direction%4;
            }
            i+=iDirection[direction];
            j+=jDirection[direction];
            cout << "i" << i << "j" << j << endl;
            if(i>=n||j>=m||i<0||j<0){
                break;
            }
            if(checker[j][i]){
                break;
            }else{
                checker[j][i] = true;
                spiral.push_back(matrix[j][i]);
            }
        }
        return spiral;
    }
};