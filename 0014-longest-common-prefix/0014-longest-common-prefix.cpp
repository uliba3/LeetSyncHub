#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string firstStr = strs[0];
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].length() < firstStr.length()){
                firstStr = strs[i];
            }
        }
        string commonPrefix = "";
        bool isCommon = true;
        for(int i = 0; i < firstStr.length(); i++){
            for(int j = 0; j < strs.size(); j++){
                if(firstStr[i]!=strs[j][i]){
                    isCommon = false;
                    break;
                }
            }
            if(!isCommon){
                break;
            }
            commonPrefix+=firstStr[i];
        }
        return commonPrefix;
    }
};