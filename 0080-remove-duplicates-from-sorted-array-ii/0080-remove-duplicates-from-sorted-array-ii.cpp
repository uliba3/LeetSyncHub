class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3){
            return nums.size();
        }
        int index = 2;
        for(int i = 2; i < nums.size(); i++){
            nums[index] = nums[i];
            if(nums[index] == nums[index - 1] && nums[index - 1] == nums[index - 2]){
                if(nums[index] != nums[i]){
                    nums[index] = nums[i];
                    index++;
                }
                continue;
            }
            index++;
        }
        if(index > 2 && 
        nums[index - 1] == nums[index - 2] && 
        nums[index - 2] == nums[index - 3]){
            index--;
        }
        return index;
    }
};