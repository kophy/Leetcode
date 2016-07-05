class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        data.push(x);
        if (min_val.empty() || min_val.top() > x)
            min_val.push(x);
        else
            min_val.push(min_val.top());
    }
    
    void pop() {
        data.pop();
        min_val.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_val.top();
    }
private:
    stack<int> data;
    stack<int> min_val;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */