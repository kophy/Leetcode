class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        // each element is added to the bottom of the stack
        stack<int> temp;
        while (!data.empty()) {
            temp.push(data.top());
            data.pop();
        }
        temp.push(x);
        while (!temp.empty()) {
            data.push(temp.top());
            temp.pop();
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
};