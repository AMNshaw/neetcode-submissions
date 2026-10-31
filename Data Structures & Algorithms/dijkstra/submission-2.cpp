class Solution {
public:
    struct HeapNode{
        HeapNode(int _n, int _cost){
            n = _n;
            cost = _cost;
        }
        int n;
        int cost;

        bool operator < (const HeapNode& other) const{
            return cost > other.cost;
        }
    };

    std::priority_queue<HeapNode> min_heap_;

    unordered_map<int, vector<pair<int, int>>> adj_list_ = {};
    
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        min_heap_ = std::priority_queue<HeapNode>();

        for(const auto& edge : edges){
            adj_list_[edge[0]].push_back({edge[1], edge[2]});
        }

        min_heap_.push(HeapNode(src, 0));

        std::unordered_map<int, int> result;
        while(!min_heap_.empty()){
            HeapNode node = min_heap_.top();
            min_heap_.pop();

            if(result.count(node.n)) continue;
            result[node.n] = node.cost;
            for(const auto& adj : adj_list_[node.n]){
                if(result.count(adj.first)) continue;
                min_heap_.push(HeapNode(adj.first, node.cost + adj.second));
            }
        }

        for(int i = 0; i < n; ++i){
            if(!result.count(i)){
                result[i] = -1;
            }
        }
        return result;
    }
};
