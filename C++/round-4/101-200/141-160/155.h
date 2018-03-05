class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        data.push(x);
        mini.push((mini.empty() || mini.top() > x)? x : mini.top());
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
    stack<int> data, mini;
};