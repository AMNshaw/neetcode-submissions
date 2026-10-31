class UnionFind{
public:
    unordered_map<int, int> parent_;
    unordered_map<int, int> rank_;

    UnionFind(vector<vector<int>>& edges){
        for(int i=0; i<edges.size(); i++){
            int v0 = edges[i][0];
            int v1 = edges[i][1];

            parent_[v0] = v0;
            parent_[v1] = v1;
            rank_[v0] = rank_[v1] = 0;
        }
    }

    int Find(int n){
        if(n != parent_[n]){
            parent_[n] = Find(parent_[n]);
        }
        return parent_[n];
    }

    bool Union(int v1, int v2){
        int p1 = Find(v1), p2 = Find(v2);
        if(p1 == p2) return false;

        if(rank_[p1] > rank_[p2]){
            parent_[p2] = p1;
        } else if(rank_[p1] < rank_[p2]){
            parent_[p1] = p2;
        } else{
            parent_[p2] = p1;
            rank_[p1]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind UF(edges);
        for(int i=0; i< edges.size(); i++){
            int v0 = edges[i][0];
            int v1 = edges[i][1];
            
            if(!UF.Union(v0, v1)){
                return {v0, v1};
            }
        }
    }
};
