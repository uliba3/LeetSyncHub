class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(int i = 0; i < magazine.length(); i++){
            if (m.contains(magazine[i])){
                m[magazine[i]]++;
            }else{
                m[magazine[i]] = 1;
            }
        }
        for(int i = 0; i < ransomNote.length(); i++){
            if(!m.contains(ransomNote[i])||m[ransomNote[i]]==0){
                return false;
            }else{
                m[ransomNote[i]]--;
            }
        }
        return true;
    }
};