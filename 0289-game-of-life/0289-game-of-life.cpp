class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> mi = {-1, 0, 1, 1, 1, 0, -1, -1};
        vector<int> mj = {-1, -1, -1, 0, 1, 1, 1, 0};
        //2 will be dead next state, -1 will revive next state
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int countLivingCells = 0;
                for(int m = 0; m < 8; m++){
                    if(i+mi[m] < 0 || j+mj[m] < 0 || i+mi[m] > board.size()-1 || j+mj[m] > board[0].size()-1){
                        continue;
                    }
                    if(board[i+mi[m]][j+mj[m]]>0){
                        countLivingCells++;
                    }
                }
                if(board[i][j] == 1&&countLivingCells<2){
                    board[i][j]=2;
                }else if(board[i][j] == 1&&countLivingCells>3){
                    board[i][j]=2;
                }else if(board[i][j] == 0&&countLivingCells==3){
                    board[i][j]=-1;
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j]==2){
                    board[i][j]=0;
                }else if(board[i][j]==-1){
                    board[i][j] = 1;
                }
            }
        }
    }
};