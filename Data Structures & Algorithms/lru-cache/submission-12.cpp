class LRUCache {
public:
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> cache_;
    list<int> keys;

    LRUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        if(!cache_.count(key)) return -1;
        auto pos = cache_[key].second;
        int value = cache_[key].first;

        keys.erase(pos);
        keys.push_back(key);
        cache_[key].second = --keys.end();

        return value;
    }
    
    void put(int key, int value) {
        if(cache_.count(key)){
            auto pos = cache_[key].second;
            keys.erase(pos);
        }
        keys.push_back(key);
        cache_[key] = {value, --keys.end()};

        if(keys.size() > cap){
            int pop_key = keys.front();
            keys.pop_front();
            cache_.erase(pop_key);
        }
    }
};
