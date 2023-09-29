class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minNum(prices.begin(), prices.end());
        vector<int> maxNum(prices.begin(), prices.end());
        for(int i = 1; i < prices.size(); i++){
            minNum[i] = min(minNum[i - 1], prices[i]);
        }
        for(int i = prices.size() - 2; i > -1; i--){
            maxNum[i] = max(maxNum[i + 1], prices[i]);
        }
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            ans = max(ans, maxNum[i] - minNum[i]);
        }
        return ans;
    }
};