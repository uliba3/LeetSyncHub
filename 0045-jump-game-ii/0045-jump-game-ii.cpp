class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> steps(nums.size(), 10001);
        steps[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j < nums[i] + 1 && i + j < nums.size(); j++){
                steps[i + j] = min(steps[i + j], steps[i] + 1);
            }
        }
        return steps[nums.size() - 1];
    }
};