class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        while (!data.empty()) {
            help.push(data.front());
            data.pop();
        }
        data.push(x);
        while (!help.empty()) {
            data.push(help.front());
            help.pop();
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
    queue<int> help;
};