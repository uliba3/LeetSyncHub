class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int sum = nums[0];
        int length = 0;
        while(r < nums.size()){
            if(sum >= target){
                if(length == 0){
                    length = r-l+1;
                }
                length = min(length, r-l+1);
            }
            while(sum <= target){
                r++;
                if(r==nums.size()){
                    return length;
                    break;
                }
                sum+=nums[r];
                if(sum >= target){
                    if(length == 0){
                        length = r-l+1;
                    }
                    length = min(length, r-l+1);
                }
            }
            while(sum >= target){
                l++;
                if(l==nums.size()){
                    return length;
                }
                sum-=nums[l-1];
                if(sum >= target){
                    if(length == 0){
                        length = r-l+1;
                    }
                    length = min(length, r-l+1);
                }
            }
            if(sum == target){
                if(length == 0){
                    length = r-l+1;
                }
                length = min(length, r-l+1);
            }
        }
        return length;
    }
};