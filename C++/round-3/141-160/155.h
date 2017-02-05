class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        mini.push(mini.empty()? x : min(mini.top(), x));
    }
    
    void pop() {
        data.pop();
        mini.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mini.top();
    }
    
private:
    stack<int> data;
    stack<int> mini;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */