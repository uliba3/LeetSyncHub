class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals;
        bool isNewInterval = false;
        for(int i = 0; i < intervals.size(); i++){
            vector<int> oldInterval = intervals[i];
            if(oldInterval[1] < newInterval[0]){
                newIntervals.push_back(oldInterval);
                continue;
            }else if(oldInterval[0] > newInterval[1]){
                if(!isNewInterval){
                    newIntervals.push_back(newInterval);
                }
                newIntervals.push_back(oldInterval);
                isNewInterval = true;
                continue;
            }else{
                newInterval[0] = min(oldInterval[0], newInterval[0]);
                newInterval[1] = max(oldInterval[1], newInterval[1]);
            }
        }
        if(!isNewInterval){
            newIntervals.push_back(newInterval);
        }
        return newIntervals;
    }
};