class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minValue = prices[0];
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] > minValue){
                profit += prices[i] - minValue;
            }
            minValue = prices[i];
        }
        return profit;
    }
};