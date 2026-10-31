class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> c_times;
        for(auto& c : tasks){
            c_times[c]++;
        }

        priority_queue<int> max_heap;
        for(auto& [c, t] : c_times){
            max_heap.push(t);
        }

        queue<pair<int, int>> q;
        int time = 0;
        while(!max_heap.empty() || !q.empty()){
            time++;
            if(!max_heap.empty()) {
                auto top = max_heap.top();
                max_heap.pop();
                if(top - 1 > 0)
                    q.push({top - 1, time + n});
            }
            
            if(!q.empty() && q.front().second == time){
                int num = q.front().first;
                max_heap.push(num);
                q.pop();
            }
        }

        return time;
    }
};
