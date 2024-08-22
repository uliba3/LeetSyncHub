class Solution {
public:
    string convert(string s, int numRows) {
        char matrix[s.length()][numRows];
        if(numRows == 1){
            return s;
        }
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < numRows; j++){
                matrix[i][j] = ' ';
            }
        }
        bool isDiagonal = false;
        int depth = 0;
        int width = 0;
        matrix[0][0] = s[0];
        for(int i = 1; i < s.length(); i++){
            if(depth==0){
                isDiagonal = false;
                depth = min(numRows-1, depth+1);
            }else if(depth==numRows-1){
                isDiagonal = true;
                depth--;
                width++;
            }else if(!isDiagonal){
                depth++;
            }else if(isDiagonal){
                depth--;
                width++;
            }
            matrix[width][depth] = s[i];
        }
        string zigzag = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < s.length(); j++){
                //cout << "i" << i << "j" << j << "mat" << matrix[j][i] << endl;
                if(matrix[j][i]!=' '){
                    zigzag+=matrix[j][i];
                }
            }
        }
        return zigzag;
    }
};