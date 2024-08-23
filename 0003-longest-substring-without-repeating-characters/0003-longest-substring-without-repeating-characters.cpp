class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, bool> m;
        int left = 0;
        int length = 0;
        int maxLength = 0;
        for(int i = 0; i < 26; i++){
            m[i] = false;
        }
        for(int right = 0; right < s.length(); right++){
            while(m[s[right]-'a']){
                length--;
                m[s[left]-'a'] = false;
                left++;
            }
            m[s[right]-'a'] = true;
            length++;
            maxLength = max(length, maxLength);
        }
        return maxLength;
    }
};