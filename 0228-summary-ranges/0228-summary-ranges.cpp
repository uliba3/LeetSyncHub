class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<vector<int>> v;
        if(nums.size()==0){
            return {};
        }
        int prevNum = nums[0];
        vector<int> vi = {prevNum};
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]-1>vi[vi.size()-1]){
                v.push_back(vi);
                vi = {nums[i]};
            }else{
                vi.push_back(nums[i]);
            }
        }
        v.push_back(vi);
        vector<string> range;
        for(int i = 0; i < v.size(); i++){
            if(v[i].size() == 1){
                range.push_back(to_string(v[i][0]));
            }else{
                range.push_back(to_string(v[i][0])+"->"+to_string(v[i][v[i].size()-1]));
            }
        }
        return range;
    }
};