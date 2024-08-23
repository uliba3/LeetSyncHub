class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pointerS = 0;
        int pointerT = 0;
        while(pointerS<s.length()&&pointerT<t.length()){
            if(s[pointerS]==t[pointerT]){
                pointerS++;
            }
            pointerT++;
        }
        if(pointerS==s.length()){
            return true;
        }else{
            return false;
        }
    }
};