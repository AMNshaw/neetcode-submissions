class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        std::stack<int> s;
        int mini = nums[0];
        s.push(0);
        for(int i=1; i < nums.size(); i++){
            if(nums[i] < mini){
                s.push(i);
                mini = nums[i];
            }
        }

        int len = 0;
        int j = nums.size() - 1;

        while(!s.empty() && j >= 0){
            if(nums[s.top()] > nums[j]){
                j--;
                continue;
            }
            len = max(len, j - s.top());
            s.pop();
        }
        return len;
    }
};
