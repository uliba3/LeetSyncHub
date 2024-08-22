class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.length(); i++){
            if(i+needle.length()-1 >= haystack.length()){
                break;
            }
            bool occur = true;
            for(int j = 0; j < needle.length(); j++){
                if(haystack[i+j]!=needle[j]){
                    occur = false;
                    break;
                }
            }
            if(occur){
                return i;
            }
        }
        return -1;
    }
};