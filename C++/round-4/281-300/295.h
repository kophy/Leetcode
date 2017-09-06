class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {}

	void addNum(int num) {
		front.push(num);
		back.push(front.top());
		front.pop();

		if (back.size() > front.size()) {
			front.push(back.top());
			back.pop();
		}
	}

	double findMedian() {
		if (front.size() > back.size())
			return front.top();
		else
			return (front.top() + back.top()) / 2.0;
	}

private:
	priority_queue<int, vector<int>, less<int>> front;      // max heap
	priority_queue<int, vector<int>, greater<int>> back;    // min heap
};