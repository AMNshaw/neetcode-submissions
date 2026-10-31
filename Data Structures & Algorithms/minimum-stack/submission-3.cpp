class MinStack {
public:
    std::stack<int> s;
    std::stack<int> minS;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minS.empty() || val < minS.top()){
            minS.push(val);
            return;
        }
        minS.push(minS.top());
    }
    
    void pop() {
        s.pop();
        minS.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};
