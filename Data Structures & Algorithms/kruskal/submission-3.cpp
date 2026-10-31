class UnionFind{
private:
    std::unordered_map<int, int> parent_;
    std::unordered_map<int, int> rank_;
public:
    UnionFind(int size) {
        parent_.reserve(size);
        rank_.reserve(size);
    }
    int find(int x){
        if(!parent_.count(x)){
            parent_[x] = x;
            rank_[x] = 1;
            return x;
        }
        if(parent_[x] == x)
            return x;
        return parent_[x] = find(parent_[x]);
    }
    bool unite(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y) return false;

        if(rank_[root_x] < rank_[root_y]){
            parent_[root_x] = root_y;
        }else if (rank_[root_x] > rank_[root_y]){
            parent_[root_y] = root_x;
        }else{
            parent_[root_x] = root_y;
            rank_[root_y] ++;
        }
        return true;
    }

};


class Solution {
private:
    struct CompareW{
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[2] > b[2];
        }
    };
    std::priority_queue<vector<int>, vector<vector<int>>, CompareW> min_heap_;
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        UnionFind uf_(n);

        for(size_t i=0; i< edges.size(); ++i){
            min_heap_.push(edges[i]);
        }
        int total_weight = 0;
        int count = 0;
        while(!min_heap_.empty()){
            const auto edge = min_heap_.top();
            min_heap_.pop();
            if(!uf_.unite(edge[0], edge[1])) continue;
            total_weight += edge[2];
            count++;
        }
        return (count != n - 1) ? -1 : total_weight;
    }
};
