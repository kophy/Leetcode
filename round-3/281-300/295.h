class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        head.push(num);
        tail.push(head.top());
        head.pop();
        if (head.size() < tail.size()) {
            head.push(tail.top());
            tail.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (head.size() > tail.size())
            return head.top();
        else
            return (head.top() + tail.top()) / 2.0;
    }

private:
    priority_queue<int, vector<int>, less<int>> head;
    priority_queue<int, vector<int>, greater<int>> tail;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();