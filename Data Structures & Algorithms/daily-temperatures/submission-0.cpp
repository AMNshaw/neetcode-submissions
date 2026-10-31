class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<pair<int, int>> st;
        int k = 0;
        st.push(std::make_pair(0, temperatures[0]));
        for(int i=1; i< n; ++i){
            int t = temperatures[i];

            while(!st.empty() && temperatures[i] > st.top().second){
                result[st.top().first] = i - st.top().first;
                st.pop();
            }
            st.push(std::make_pair(i, temperatures[i]));
        }
        return result;
    }
};
