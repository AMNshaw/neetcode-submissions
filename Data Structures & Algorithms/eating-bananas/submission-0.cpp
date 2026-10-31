class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int l = 1, r = piles[piles.size() - 1], mid;

        while(l < r){
            mid = (l + r)/2;
            int k = 0;
            for(auto &p : piles){
                k += p/mid;
                if(p % mid > 0)
                    k++;
            }
            if(k <= h)
                r = mid;
            else 
                l = mid + 1;

        }
        return l;
    }   
};
