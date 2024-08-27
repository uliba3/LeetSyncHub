class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        map<char, char> oppositeM;
        for(int i = 0; i < s.length(); i++){
            if(m.contains(s[i])){
                if(m[s[i]]!=t[i]){
                    return false;
                }
            }else{
                m[s[i]] = t[i];
            }
            if(oppositeM.contains(t[i])){
                if(oppositeM[t[i]]!=s[i]){
                    return false;
                }
            }else{
                oppositeM[t[i]] = s[i];
            }
        }
        return true;
    }
};