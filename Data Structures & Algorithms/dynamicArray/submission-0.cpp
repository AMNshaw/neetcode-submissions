class DynamicArray {
public:

    DynamicArray(int capacity) {
        capacity_ = capacity;
        size_ = 0;
        arr_ = new int[capacity]();
    }

    int get(int i) {
        return arr_[i];
    }

    void set(int i, int n) {
        arr_[i] = n;
    }

    void pushback(int n) {
        if(size_ == capacity_){
            resize();
        }
        arr_[size_] = n;
        size_++;
    }

    int popback() {
        size_ --;
        return arr_[size_];
    }

    void resize() {
        capacity_ *= 2;
        int* new_arr = new int[capacity_]();
        for(size_t i=0; i < size_; ++i){
            new_arr[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = new_arr;
    }

    int getSize() {
        return size_;
    }

    int getCapacity() {
        return capacity_;
    }

private:
    int capacity_;
    int size_;
    int* arr_;
};
