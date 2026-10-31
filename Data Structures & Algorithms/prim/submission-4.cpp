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
        // 優化 1：使用 vector<vector<...>> 替代 unordered_map
        // 預先 reserve 空間可以減少動態擴容產生的記憶體碎片
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        priority_queue<HeapNode> min_heap;
        // 優化 2：使用 vector<bool> 替代 unordered_set，空間極小且訪問速度更快
        vector<bool> visited(n, false);
        
        // 初始化：從節點 0 開始（權重為 0 的虛擬邊）
        min_heap.push(HeapNode(0, 0));
        
        int mst_weight = 0;
        int nodes_count = 0;

        while (!min_heap.empty() && nodes_count < n) {
            HeapNode top = min_heap.top();
            min_heap.pop();

            // 這裡就是你之前問的：上層檢查，處理 Heap 中的重複舊數據
            if (visited[top.node]) continue;

            visited[top.node] = true;
            mst_weight += top.weight;
            nodes_count++;

            for (const auto& neighbor : adj[top.node]) {
                // 下层檢查：只將尚未加入 MST 的鄰居放入 Heap
                if (!visited[neighbor.first]) {
                    min_heap.push(HeapNode(neighbor.first, neighbor.second));
                }
            }
        }

        return (nodes_count == n) ? mst_weight : -1;
    }
};

