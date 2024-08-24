class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int col = 0; col < 9; col++){
            map<int, bool> m;
            for(int row = 0; row < 9; row++){
                if(board[row][col] == '.'){
                    continue;
                }
                cout << "col" << col << "row" << row << endl;
                if(!m.contains(board[row][col])){
                    m[board[row][col]] = true;
                }else{
                    return false;
                }
            }
        }
        for(int row = 0; row < 9; row++){
            map<int, bool> m;
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    continue;
                }
                if(!m.contains(board[row][col])){
                    m[board[row][col]] = true;
                }else{
                    return false;
                }
            }
        }
        vector<int> colSq = {0, 1, 2};
        vector<int> rowSq = {0, 1, 2};
        for(int colVal : colSq){
            for(int rowVal : rowSq){
                map<int, bool> m;
                for(int col = colVal*3; col < colVal*3 + 3; col++){
                    for(int row = rowVal*3; row < rowVal*3 + 3; row++){
                        if(board[row][col] == '.'){
                            continue;
                        }
                        if(!m.contains(board[row][col])){
                            m[board[row][col]] = true;
                        }else{
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};