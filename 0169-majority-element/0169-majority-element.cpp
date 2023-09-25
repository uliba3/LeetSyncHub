class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int>count;
        for(int i = 0; i < n; i++){
            count[nums[i]] = 0;
        }
        for(int i = 0; i < n; i++){
            count[nums[i]]++;
        }
        for(auto element :count){
            if(element.second > n/2){
                return element.first;
            }
        }
        return -1;
    }
};