class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int area = (r-l)*min(height[l], height[r]);
        while(l<r){
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
            area = max(area, (r-l)*min(height[l], height[r]));
        }
        return area;
    }
};