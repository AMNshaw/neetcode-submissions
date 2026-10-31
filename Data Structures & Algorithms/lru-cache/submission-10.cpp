class LRUCache {
public:
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> cache_;
    list<int> keys_list;
    LRUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        if(!cache_.count(key)) return -1;
        int val = cache_[key].first;
        auto position = cache_[key].second;

        keys_list.erase(position);
        keys_list.push_back(key);
        cache_[key].second = --keys_list.end();

        return val;
    }
    
    void put(int key, int value) {
        if(cache_.count(key)){
            auto position = cache_[key].second;
            keys_list.erase(position);
        }
        keys_list.push_back(key);
        cache_[key] = std::make_pair(value, --keys_list.end());
        
        if(keys_list.size() > cap){
            int key = keys_list.front();
            cache_.erase(key);
            keys_list.pop_front();
        }
    }
};
