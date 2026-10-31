class LRUCache {
public:
    int cap_=0;
    LRUCache(int capacity) : cap_(capacity) {}
    
    unordered_map<int, pair<int, list<int>::iterator>> cache_;

    list<int> keys;

    int get(int key) {
        if(!cache_.count(key)) return -1;
        int val = cache_[key].first;
        
        keys.erase(cache_[key].second);
        keys.push_back(key);
        cache_[key].second = --keys.end();

        return val;
    }
    
    void put(int key, int value) {
        if(cache_.count(key)){
            keys.erase(cache_[key].second);
            cache_.erase(key);
        }

        keys.push_back(key);
        cache_[key] = {value, --keys.end()};

        if(keys.size() > cap_){
            int LRUkey = keys.front();
            keys.pop_front();
            cache_.erase(LRUkey);
;        }

    }
};
