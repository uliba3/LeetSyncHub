class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        for(int i = 1; i < 1001; i++){
            int count = 0;
            for(int j = 0; j < citations.size(); j++){
                if(citations[j] >= i){
                    count++;
                }
            }
            if(count >= i){
                ans = i;
            }
        }
        return ans;
    }
};