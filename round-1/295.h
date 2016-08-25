class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        first_half.emplace(num);
        second_half.emplace(first_half.top());
        first_half.pop();
        if (first_half.size() < second_half.size()) {
            first_half.emplace(second_half.top());
            second_half.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if ((first_half.size() + second_half.size()) % 2 == 0)
            return (first_half.top() + second_half.top()) / 2.0;
        else
            return first_half.top();
    }
private:
    priority_queue<int, vector<int>, less<int> > first_half;
    priority_queue<int, vector<int>, greater<int> > second_half;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();