class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> overlapIntervals;
        overlapIntervals.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            vector<int> overlap = overlapIntervals[overlapIntervals.size()-1];
            if(intervals[i][0] > overlap[1]){
                overlapIntervals.push_back(intervals[i]);
                continue;
            }
            overlap[1] = max(intervals[i][1], overlap[1]);
            overlapIntervals[overlapIntervals.size()-1] = overlap;
        }
        return overlapIntervals;
    }
};