class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.length();
        int m = num2.length();
        std::vector<int> res_v(n + m, 0);

        for(int j = m-1; j >= 0; j--){
            int n_j = int(num2[j] - '0');
            int ov = 0;
            for(int i = n-1; i >= 0; i--){
                int n_i = int(num1[i] - '0');

                int sum = n_i * n_j + res_v[i + j + 1];
                res_v[i + j + 1] = sum % 10;
                res_v[i + j] += sum / 10;
            }
        }
        std::string res = "";
        int idx = 0;
        while(idx < res_v.size() && res_v[idx] == 0){
            idx++;
        }
        for(int i = idx; i < res_v.size(); ++i){
            res = res + std::to_string(res_v[i]);
        }
        return res.empty() ? "0" : res;
    }

};
