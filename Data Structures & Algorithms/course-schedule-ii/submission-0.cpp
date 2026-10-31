class Solution {
    std::unordered_map<int, vector<int>> adj_list_;
    std::unordered_map<int, int> in_degree_;
    std::queue<int> q_;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        init(numCourses, prerequisites);


        std::vector<int> result{};
        result.reserve(numCourses);
        while(!q_.empty()){
            int crs = q_.front();
            q_.pop();
            result.push_back(crs);
            const auto nexts = adj_list_[crs];
            for(int i=0; i< nexts.size(); ++i){
                in_degree_[nexts[i]]--;
                if(in_degree_[nexts[i]] == 0){
                    q_.push(nexts[i]);
                }
            }
        }

        return result.size() == numCourses? result : std::vector<int>{};
    }

    void init(int n, vector<vector<int>>& prerequisites){
        adj_list_.reserve(n);
        in_degree_.reserve(n);

        for(int i=0; i< n; ++i){
            in_degree_[i] = 0;
        }

        for(int i=0; i < prerequisites.size(); ++i){
            int src = prerequisites[i][1];
            int dst = prerequisites[i][0];
            adj_list_[src].push_back(dst);
            in_degree_[dst] ++;
        }

        for(int i=0; i< n; i++){
            if(in_degree_[i] == 0)
                q_.push(i);
        }
    }
};