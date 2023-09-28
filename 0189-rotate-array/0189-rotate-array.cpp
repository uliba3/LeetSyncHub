class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<bool> renewed(nums.size());
        if(k == 0){
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            renewed[i]=false;
        }
        for(int i = 0; i < nums.size(); i++){
            if(renewed[i]){
                continue;
            }
            int renewIndex = i;
            renewIndex += k;
            renewIndex %= nums.size();
            int leftValue = nums[i];
            while(!renewed[renewIndex]){
                swap(leftValue, nums[renewIndex]);
                renewed[renewIndex] = true;
                renewIndex += k;
                renewIndex %= nums.size();
            }
        }
        for(int i = nums.size() - 1; i > -1; i--){
            if(renewed[i]){
                continue;
            }
            int renewIndex = i;
            renewIndex -= k;
            if(renewIndex < 0){
                renewIndex += nums.size();
            }
            int leftValue = nums[i];
            while(!renewed[renewIndex]){
                swap(leftValue, nums[renewIndex]);
                renewed[renewIndex] = true;
                renewIndex -= k;
                if(renewIndex < 0){
                    renewIndex += nums.size();
                }
            }
        }
    }
};