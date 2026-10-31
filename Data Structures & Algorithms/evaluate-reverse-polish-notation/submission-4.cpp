class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> op = {"+", "-", "*", "/"};

        stack<int> num;

        for(auto &t : tokens){
            if(!op.count(t)){
                num.push(stoi(t));
                continue;
            }
            int a = num.top(); num.pop();
            int b = num.top(); num.pop();
            int c;
                
            if(t == "+"){
                c = b + a;
            }else if(t == "-"){
                c = b - a;
            }else if(t == "*"){
                c = b * a;
            }else if(t == "/"){
                c = b / a;
            }
            num.push(c);
        }
        return num.top();

    }
};
