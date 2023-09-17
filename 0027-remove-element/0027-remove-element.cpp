class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        while(i < j){
            if(nums[i] != val){
                i++;
                continue;
            }else if(nums[j] == val){
                j--;
                continue;
            }
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        int k = 0;
        for(int l = 0; l < nums.size(); l++){
            if(nums[l] != val){
                k++;
            }
        }
        return k;
    }
};