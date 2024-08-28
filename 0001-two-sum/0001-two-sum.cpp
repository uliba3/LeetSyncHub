class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        map<int, vector<int>> mi;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
            mi[nums[i]].push_back(i);
        }
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]--;
            if(m[target-nums[i]]>0 && target-nums[i] != nums[i]){
                return {mi[nums[i]][0], mi[target-nums[i]][0]};
            }else if(m[target-nums[i]]>0 && target-nums[i] == nums[i]){
                return {mi[nums[i]][0], mi[target-nums[i]][1]};
            }
            m[nums[i]]++;
        }
        return {};
    }
};