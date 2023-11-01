class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n);
        vector<int> r(n);
        vector<int> a(n);
        l[0] = 1;
        r[nums.size()-1] = 1;
        for(int i = 1; i < n; i++){
            l[i] = l[i-1]*nums[i-1];
            r[n-1-i] = r[n - i]*nums[n-i];
        }
        a[0] = r[0];
        a[n-1] = l[n-1];
        for(int i = 1; i < n-1; i++){
            a[i] = l[i]*r[i];
        }
        return a;
    }
};