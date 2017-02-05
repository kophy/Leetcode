class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue<int> temp;
        while (!data.empty()) {
            temp.push(data.front());
            data.pop();
        }
        data.push(x);
        while (!temp.empty()) {
            data.push(temp.front());
            temp.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        data.pop();
    }

    // Get the top element.
    int top() {
        return data.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return data.empty();
    }
    
private:
    queue<int> data;
};