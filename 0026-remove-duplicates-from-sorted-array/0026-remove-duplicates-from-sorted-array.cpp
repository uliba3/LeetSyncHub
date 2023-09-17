class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1, lastNum = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != lastNum){
                nums[index] = nums[i];
                lastNum = nums[i];
                index++;
            }
        }
        return index;
    }
};