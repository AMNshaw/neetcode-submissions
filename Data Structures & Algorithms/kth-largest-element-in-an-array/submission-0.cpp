class Solution {
public:
    static bool cmpr(int a, int b){ return a > b;}
    priority_queue<int, vector<int>, bool(*)(int, int)> pq;

    Solution() : pq(&cmpr){}

    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
