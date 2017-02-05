class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!data.empty()) {
            help.push(data.top());
            data.pop();
        }
        help.push(x);
        while (!help.empty()) {
            data.push(help.top());
            help.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        data.pop();
    }

    // Get the front element.
    int peek(void) {
        return data.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return data.empty();
    }
private:
    stack<int> data;
    stack<int> help;
};