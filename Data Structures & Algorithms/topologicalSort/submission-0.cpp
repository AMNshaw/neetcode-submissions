class Solution {
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        init(n, edges);

        std::vector<int> result = {};

        while(!q_.empty()){
            int node = q_.front();
            result.push_back(node);
            q_.pop();
            std::vector<int> adj = adj_list_[node];
            for(size_t i=0; i< adj.size(); ++i){
                int neighbor = adj[i];
                degree_[neighbor]--;
                if(degree_[neighbor] == 0){
                    q_.push(neighbor);
                }
            }
        }

        return result.size() == n ? result : vector<int>{};

    }
private:
    std::unordered_map<int, vector<int>> adj_list_;
    std::unordered_map<int, int> degree_;
    std::queue<int> q_;

    void init(int n, vector<vector<int>>& edges){
        for(size_t i=0; i< n; ++i){
            degree_[i] = 0;
        }

        adj_list_.reserve(n);
        for(size_t i=0; i< edges.size(); ++i){
            int src = edges[i][0];
            int dst = edges[i][1];
            adj_list_[src].push_back(dst);
            degree_[dst]++;
        }

        for(const auto& [node, deg] : degree_){
            if(deg == 0){
                q_.push(node);
            }
        }
    }
};
