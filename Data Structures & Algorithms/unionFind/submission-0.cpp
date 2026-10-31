class UnionFind {
private:
    std::vector<int> parent_;
    std::vector<int> rank_;
    int count_;
public:
    UnionFind(int n) : count_(n) {
        parent_.resize(n);
        std::iota(parent_.begin(), parent_.end(), 0);
        rank_.resize(n);
    }

    int find(int x) {
        if(parent_[x] == x)
            return x;
        return parent_[x] = find(parent_[x]);
    }

    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y) return false;

        if(rank_[root_x] < rank_[root_y]){
            parent_[x] = root_y;
        }else if(rank_[root_x] > rank_[root_y]){
            parent_[y] = root_x;
        }else{
            parent_[root_x] = root_y;
            rank_[root_x] ++;
        }
        count_ --;
        return true;
    }

    int getNumComponents() {
        return count_;
    }
};
