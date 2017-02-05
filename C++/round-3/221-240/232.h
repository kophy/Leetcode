class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        while (!data.empty()) {
            temp.push(data.top());
            data.pop();
        }
        data.push(x);
        while (!temp.empty()) {
            data.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int v = peek();
        data.pop();
        return v;
    }
    
    /** Get the front element. */
    int peek() {
        return data.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
    
private:
    stack<int> data;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */