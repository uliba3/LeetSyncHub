class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        map<char, int> m;
        for(int i = 0; i < s.length(); i++){
            if(m.contains(s[i])){
                m[s[i]]++;
            }else{
                m[s[i]] = 1;
            }
        }
        for(int i = 0; i < t.length(); i++){
            if(!m.contains(t[i])){
                return false;
            }
            m[t[i]]--;
            if(m[t[i]] < 0){
                return false;
            }
        }
        return true;
    }
};