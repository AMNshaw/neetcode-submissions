class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;

        int max_area = 0;
        while(i < j){
            int len = j - i;

            int height = 0;
            if(heights[j] > heights[i]){
                height = heights[i];
                i++;
            }else{
                height = heights[j];
                j--;
            }

            int area = height * len;
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
