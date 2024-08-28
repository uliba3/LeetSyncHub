class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mstr;
        for(int i = 0; i < strs.size(); i++){
            string strBefore = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mstr[strs[i]].push_back(strBefore);
        }
        vector<vector<string>> strM;
        for(auto m : mstr){
            strM.push_back(m.second);
        }
        return strM;
    }
};