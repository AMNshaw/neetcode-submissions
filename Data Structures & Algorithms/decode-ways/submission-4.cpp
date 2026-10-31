class Solution {
public:
    vector<int> memo;
    int n;
    int numDecodings(string s) {
        n = s.length();
        memo.assign(n, -1);
        return dfs(0, s);
        
    }

    int dfs(int i, string& s){
        if(i == n) return 1;

        if(s[i] == '0') return 0;

        if(memo[i] != -1) return memo[i];

        int res = dfs(i+1, s);

        if(i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))){
            res += dfs(i+2, s);
        }

        return memo[i] = res;
    }
};
