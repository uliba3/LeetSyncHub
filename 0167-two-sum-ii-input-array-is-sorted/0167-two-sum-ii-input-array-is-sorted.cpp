class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        while(numbers[l] + numbers[r] != target){
            if(numbers[l] + numbers[r] > target){
                r--;
            }else if(numbers[l] + numbers[r] < target){
                l++;
            }
        }
        vector<int> solution;
        solution.push_back(l+1);
        solution.push_back(r+1);
        return solution;
    }
};