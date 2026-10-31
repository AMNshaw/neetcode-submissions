class Solution {
public:

    struct HeapNode{
        HeapNode(int cost, int node) : cost(cost), node(node) {}
        int cost;
        int node;
        bool operator<(const HeapNode& other) const {
            return cost > other.cost;
        }
    };
    std::priority_queue<HeapNode> min_heap_;

    unordered_map<int, vector<pair<int, int>>> adjacency_list_ = {};
    
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        init(edges, src, n);

        std::unordered_map<int, int> shortest = {};

        while(!min_heap_.empty()){
            HeapNode top = min_heap_.top();
            min_heap_.pop();

            if(shortest.count(top.node)){
                continue;
            }
            shortest[top.node] = top.cost;

            for(const auto& vw : adjacency_list_[top.node]){
                const int vertex = vw.first;
                const int weight = vw.second;
                if(!shortest.count(vertex)){
                    min_heap_.push(HeapNode(top.cost + weight, vertex));
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (shortest.find(i) == shortest.end()) {
                shortest[i] = -1;            
            }
        }
        return shortest;
    }

    void init(vector<vector<int>>& edges, int src, int n){
        min_heap_ = std::priority_queue<HeapNode>();
        adjacency_list_.clear();
        for(const auto& edge : edges){
            adjacency_list_[edge[0]].push_back({edge[1], edge[2]});
        }

        min_heap_.push(HeapNode(0, src));
    }
};
