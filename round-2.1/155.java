public class MinStack {

    /** initialize your data structure here. */
    private Stack<Integer> data;
    private Stack<Integer> mini;

    public MinStack() {
        data = new Stack<Integer>();
        mini = new Stack<Integer>();
    }

    public void push(int x) {
        data.push(x);
        mini.push((mini.isEmpty() || mini.peek() > x)? x : mini.peek());

    }

    public void pop() {
        data.pop();
        mini.pop();
    }

    public int top() {
        return data.peek();
    }

    public int getMin() {
        return mini.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */