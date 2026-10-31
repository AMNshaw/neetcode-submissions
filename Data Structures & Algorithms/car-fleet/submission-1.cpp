class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n <= 1) return n;

        std::vector<std::pair<int, int>> car_infos(n, {0, 0});
        for(int i=0; i < n; i++){
            car_infos[i] = std::make_pair(position[i], speed[i]);
        } 
        std::sort(car_infos.begin(), car_infos.end(), [](const auto& a, const auto& b){
            return a.first > b.first;
        });

        std::stack<double> time_stack;
        time_stack.push(time_arrive(target, car_infos[0]));
        int res = 1;

        for(int i=1; i < n; i++){
            double t = time_arrive(target, car_infos[i]);
            if(time_stack.top() < t){
                res++;
                time_stack.push(t);
            }
        }
        return res;
    }

    double time_arrive(int target, std::pair<int, int>& car_info){
        return (double)(target - car_info.first) / car_info.second;
    }
};
