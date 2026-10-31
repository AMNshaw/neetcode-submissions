class Solution {
public:
    std::map<int, int> cache;
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        if(cache.find(n) != cache.end())
            return cache[n];
        
        cache[n] = climbStairs(n-1) + climbStairs(n-2);

        return cache[n];
    }
};
