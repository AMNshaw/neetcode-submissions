class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;

        int max_area = 0;
        while(i < j){
            int water = min(heights[i], heights[j]) * (j - i);
            if(heights[j] > heights[i]){
                i++;
            }else{
                j--;
            }
            max_area = max(max_area, water);
        }
        return max_area;
    }
};
