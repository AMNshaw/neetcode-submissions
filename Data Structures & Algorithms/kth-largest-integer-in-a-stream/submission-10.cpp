class KthLargest {
public:
    priority_queue<int> pq_;
    int kth_;
    KthLargest(int k, vector<int>& nums) {
        for(auto &num : nums)
            pq_.push(num);
        kth_ = k;
    }
    
    int add(int val) {
        pq_.push(val);
        priority_queue<int> pq_tmp = pq_;
        for(int i=0; i<kth_-1; i++){
            pq_tmp.pop();
        }
        return pq_tmp.top();
    }
};
