struct HeapNode{
    HeapNode(int nd, int wt) : node(nd), weight(wt){}
    int node = 0;
    int weight = 0;
    bool operator<(const HeapNode& other) const {
        return weight > other.weight;
    }
};

class Solution {
public:
    unordered_map<int, std::vector<pair<int, int>>> adj_list_;
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        adj_list_.clear();
        for(int i=0; i< edges.size(); ++i){
            int src = edges[i][0];
            int dst = edges[i][1];
            int weight = edges[i][2];
            adj_list_[src].push_back({dst, weight});
            adj_list_[dst].push_back({src, weight});
        }
        std::priority_queue<HeapNode> min_heap;
        unordered_set<int> visit_set;
        
        visit_set.insert(0);
        for(const auto& [n, w] : adj_list_[0]){
            min_heap.push(HeapNode(n, w));
        }
        int result = 0;

        while(!min_heap.empty() && visit_set.size() < n){
            HeapNode top = min_heap.top();
            min_heap.pop();
            
            if (visit_set.count(top.node)) continue;

            result += top.weight;
            visit_set.insert(top.node);

            for(const auto& [n, w] : adj_list_[top.node]){
                if (visit_set.find(n) == visit_set.end()) {
                    min_heap.push(HeapNode(n, w));
                }
            }
        }

        return visit_set.size() == n ? result : -1;

    }
};

