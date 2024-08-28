class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        map<int, bool> m;
        for(int r = 0; r < nums.size(); r++){
            if(l < r-k){
                m[nums[l]] = false;
                l = r-k;
            }
            if(m[nums[r]]){
                return true;
            }
            m[nums[r]] = true;
        }
        return false;
    }
};