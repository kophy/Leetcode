class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        // move the head and tail half
        tail.push(num);
        head.push(tail.top());
        tail.pop();

        // head adds one element(+1), tail adds and deletes one number(0)
        if (head.size() > tail.size()) {
            tail.push(head.top());
            head.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (head.size() == tail.size())
            return (head.top() + tail.top()) / 2.0;
        else
            return tail.top();
    }

private:
    priority_queue<int, vector<int>, less<int>> head; 		// the head half, a max heap
    priority_queue<int, vector<int>, greater<int>> tail;	// the tail half, a min heap
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();