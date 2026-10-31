class LRUCache {
public:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> keys;
    int cap_;
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;

        int getValue = cache[key].first;
        keys.erase(cache[key].second);
        keys.push_back(key);
        cache[key].second = --keys.end();

        return getValue;
    }
    
    void put(int key, int value) {
        if(cache.count(key))
            keys.erase(cache[key].second);
        
        keys.push_back(key);
        cache[key] = {value, --keys.end()};

        if(keys.size() > cap_){
            int LRU = keys.front();
            keys.pop_front();
            cache.erase(LRU);
        }
        
    }
};
