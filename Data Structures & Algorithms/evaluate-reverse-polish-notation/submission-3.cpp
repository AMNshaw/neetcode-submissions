class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> op = {"+", "-", "*", "/"};

        stack<int> st;
        int result = 0;
        for(const auto& t : tokens){
            if(op.count(t)){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (t == "+")
                    result = a + b;
                else if (t == "-")
                    result = a - b;
                else if (t == "*")
                    result = a * b;
                else 
                    result = a / b;

                st.push(result);
            }
            else
                st.push(stoi(t));
        }
        return st.top();
    }
};
