class LRUCache {
public:
    unordered_map<int, pair<int, list<int>::iterator>> cache_;
    list<int> order_;
    int capacity_;

    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        if(cache_.find(key) == cache_.end()) return -1;

        order_.erase(cache_[key].second); 
        order_.push_back(key); // move the key to the right
        cache_[key].second = --order_.end(); // store the iterator of the key

        return cache_[key].first; // return the val
    }
    
    void put(int key, int value) {
        if(cache_.find(key) != cache_.end())
            order_.erase(cache_[key].second);
        
        else if(cache_.size() == capacity_){
            int LRU = order_.front(); // front key
            order_.pop_front(); // remove front key
            cache_.erase(LRU); // remove LRU key
        }

        order_.push_back(key); 
        cache_[key] = {value, --order_.end()};

    }
};
