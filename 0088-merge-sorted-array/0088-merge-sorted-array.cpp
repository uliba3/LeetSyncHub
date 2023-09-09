class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> copyNums1;
        for(int i = 0; i < m; i++){
            copyNums1.push_back(nums1[i]);
        }
        int l = 0, r = 0;
        while(l < m || r < n){
            int pos = l + r;
            if(l == m){
                nums1[pos] = nums2[r];
                r++;
            }else if(r == n){
                nums1[pos] = copyNums1[l];
                l++;
            }else if(copyNums1[l] <= nums2[r]){
                nums1[pos] = copyNums1[l];
                l++;
            }else if(copyNums1[l] > nums2[r]){
                nums1[pos] = nums2[r];
                r++;
            }
        }
    }
};