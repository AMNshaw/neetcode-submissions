class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(text1[i] == text2[j])
                    grid[i][j] = grid[i+1][j+1] + 1;
                else
                    grid[i][j] = max(grid[i+1][j], grid[i][j+1]);
            }
        }
        return grid[0][0];
    }
};
