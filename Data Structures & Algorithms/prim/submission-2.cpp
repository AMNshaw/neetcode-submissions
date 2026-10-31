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
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        // 1. 改用 vector 替代 unordered_map，空間更緊湊
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<HeapNode> min_heap;
        // 2. 改用 vector<bool> 替代 unordered_set，記憶體直接省下數倍
        vector<bool> visited(n, false);
        
        min_heap.push(HeapNode(0, 0)); // 從節點 0 開始，初始權重為 0
        int result = 0;
        int visited_count = 0;

        while (!min_heap.empty() && visited_count < n) {
            HeapNode top = min_heap.top();
            min_heap.pop();

            if (visited[top.node]) continue;

            visited[top.node] = true;
            result += top.weight;
            visited_count++;

            for (const auto& [neighbor, weight] : adj[top.node]) {
                if (!visited[neighbor]) {
                    min_heap.push(HeapNode(neighbor, weight));
                }
            }
        }

        return (visited_count == n) ? result : -1;
    }
};

