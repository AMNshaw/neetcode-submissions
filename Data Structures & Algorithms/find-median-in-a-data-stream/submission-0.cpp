class MedianFinder {
public:

    priority_queue<int> small_;
    priority_queue<int, vector<int>, greater<int>> large_; 
    MedianFinder() {}
    
    void addNum(int num) {
        small_.push(num);

        if(small_.size() != 0 && large_.size() != 0 && small_.top() > large_.top()){
            large_.push(small_.top());
            small_.pop();
        }

        if(small_.size() > large_.size()+1){
            large_.push(small_.top());
            small_.pop();
        }else if(large_.size() > small_.size()+1){
            small_.push(large_.top());
            large_.pop();
        }
    }
    
    double findMedian() {
        if(small_.size() > large_.size()){
            return small_.top();
        }else if(large_.size() > small_.size()){
            return large_.top();
        }
        auto d1 = static_cast<double>(small_.top());
        auto d2 = static_cast<double>(large_.top());

        return (d1 + d2)/2;
    }
};
