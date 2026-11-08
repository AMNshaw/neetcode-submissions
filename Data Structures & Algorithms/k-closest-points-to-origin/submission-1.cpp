class Solution {
public:
    struct Pt{
        int x;
        int y;
        int dist_2;

        bool operator<(const Pt& other) const{
            return dist_2 > other.dist_2;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<Pt> heap;  

        for(auto& pt : points){
            Pt p{pt[0], pt[1], dist2(pt)};
            heap.push(p);
        }

        std::vector<std::vector<int>> res(k, {0, 0});
        for(int i = 0; i < k; ++i){
            auto p = heap.top();
            heap.pop();
            res[i] = {p.x, p.y};
        }
        return res;
    }

    int dist2(std::vector<int>& pt){
        return pt[0] * pt[0] + pt[1] * pt[1];
    }
};
