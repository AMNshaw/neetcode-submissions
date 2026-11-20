class Solution {
public:
    struct HeapNode{
        int src = 0;
        int dist = 0;

        bool operator>(const HeapNode& other) const{
            return dist > other.dist;
        }
    };

    unordered_map<int, vector<pair<int, int>>> adj_list_ = {};
    
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {

        for(auto& edge : edges){
            adj_list_[edge[0]].push_back({edge[1], edge[2]});
        }

        std::unordered_map<int, int> result;

        std::priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> heap;
        heap.push(HeapNode{src, 0});

        while(!heap.empty()){
            auto curr = heap.top();
            heap.pop();
            if(result.count(curr.src)) continue;

            result[curr.src] = curr.dist;

            for(auto& adj : adj_list_[curr.src]){
                heap.push(HeapNode{adj.first, adj.second + curr.dist});
            }
        }

        for(int i = 0; i < n; ++i){
            if(!result.count(i)) result[i] = -1;
        }

        return result;
    }
};
