class MinStack {
private:
    stack<int> s; // Stack to store values
    map<int, int> m;
    int minNum;
public:
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(s.size()==1||val < minNum){
            minNum = val;
            m[s.size()] = minNum;
        }else{
            m[s.size()] = minNum;
        }
    }
    
    void pop() {
        s.pop();
        minNum = m[s.size()];
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minNum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */