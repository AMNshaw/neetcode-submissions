class MinHeap {
public:
    MinHeap() {
        heap_.push_back(0); // Dummy element at index 0
    }

    void push(int val) {
        heap_.push_back(val);
        bubbleUp(heap_.size() - 1);
    }

    int pop() {
        if (heap_.size() <= 1) {
            return -1;
        }
        int top = heap_[1];
        if (heap_.size() == 2) {
            heap_.pop_back();
            return top;
        }
        heap_[1] = heap_.back();
        heap_.pop_back();
        bubbleDown(1);
        return top;
    }

    int top() {
        return heap_.size() > 1 ? heap_[1] : -1;
    }

    void heapify(const vector<int>& arr) {
        heap_ = {0};
        heap_.insert(heap_.end(), arr.begin(), arr.end());
        for(int i=(heap_.size() / 2 + 1); i >= 1; i--){
            bubbleDown(i);
        }
    }

private:
    void bubbleUp(int idx) {
        // parent: i / 2
        int parent_idx = idx / 2;
        while(idx > 1 && heap_[idx] < heap_[parent_idx]){
            std::swap(heap_[idx], heap_[parent_idx]);
            idx = parent_idx;
            parent_idx = idx / 2;
        }
    }

    void bubbleDown(int idx) {
        // child_left = 2*idx, child_right = 2*idx + 1
        int child = 2 * idx;
        while(child < heap_.size()){
            if(child + 1 < heap_.size() && heap_[child + 1] < heap_[child]){
                child += 1;
            }
            if(heap_[child] >= heap_[idx]) return;

            std::swap(heap_[idx], heap_[child]);
            idx = child;
            child = 2 * idx;
        }
    }

    std::vector<int> heap_;
};