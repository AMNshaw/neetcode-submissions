class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visit;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        if(prerequisites.empty()) return true;

        for(auto &p : prerequisites){
            int src = p[0], dst = p[1];
            adjList[src].push_back(dst);
        }


         for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs){
        if(visit.find(crs) != visit.end()) return false;

        if(adjList[crs].empty()) return true;

        visit.insert(crs);

        for(int &p : adjList[crs]){
            if(!dfs(p))
                return false;
        }

        visit.erase(crs);
        adjList[crs].clear();
        return true;
    }
};
