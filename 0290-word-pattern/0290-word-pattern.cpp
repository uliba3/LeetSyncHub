class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> m;
        map<string, char> oppositeM;
        vector<string> words;
        string word;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                words.push_back(word);
                word="";
            }else{
                word+=s[i];
            }
        }
        words.push_back(word);
        if(pattern.length()!=words.size()){
            return false;
        }
        for(int i = 0; i < pattern.length(); i++){
            if(m.contains(pattern[i])){
                if(m[pattern[i]]!=words[i]){
                    return false;
                }
            }else{
                m[pattern[i]] = words[i];
            }
            if(oppositeM.contains(words[i])){
                if(oppositeM[words[i]]!=pattern[i]){
                    return false;
                }
            }else{
                oppositeM[words[i]] = pattern[i];
            }
        }
        return true;
    }
};