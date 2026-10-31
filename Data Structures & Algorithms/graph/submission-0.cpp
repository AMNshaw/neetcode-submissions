class Graph {
public:
    Graph() {

    }

    void addEdge(int src, int dst) {
        adj_list_[src].insert(dst);
        if (adj_list_.find(dst) == adj_list_.end()) {
            adj_list_[dst] = {};
        }
    }

    bool removeEdge(int src, int dst) {
        auto src_it = adj_list_.find(src);
        if(src_it == adj_list_.end()) return false;
        auto dst_it = src_it->second.find(dst);
        if(dst_it == src_it->second.end()) return false;
        src_it->second.erase(dst_it);
        return true;
    }

    bool hasPath(int src, int dst) {
        

        std::queue<int> q;
        q.push(src);
        std::unordered_set<int> visit;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == dst) return true;
            if(visit.count(node)) continue;
            visit.insert(node);

            auto it = adj_list_.find(node);
            if (it != adj_list_.end()) {
                for(const auto& next : it->second){
                    if(!visit.count(next))
                        q.push(next);
                }
            }
        }
        return false;
    }

private:
    std::unordered_map<int, std::unordered_set<int>> adj_list_;

};
