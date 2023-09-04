class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> alphabets(26,0);
        for(int i = 0; i < magazine.size(); i++){
            alphabets[magazine[i]-'a']++;
        }
        for(int i = 0; i < ransomNote.size(); i++){
            alphabets[ransomNote[i] - 'a']--;
        }
        bool res = true;
        for(int i = 0; i < 26; i++){
            if(alphabets[i] < 0){
                res = false;
            }
        }
        return res;
    }
};