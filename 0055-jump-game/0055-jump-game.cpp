class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            steps--;
            steps = max(nums[i], steps);
            if(steps <= 0){
                return false;
            }
        }
        return true;
    }
};