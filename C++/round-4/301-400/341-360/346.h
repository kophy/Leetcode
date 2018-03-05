class MovingAverage {
public:
	/** Initialize your data structure here. */
	MovingAverage(int size) {
		sum_ = 0;
		size_ = size;
	}

	double next(int val) {
		sum_ += val;
		data.push(val);

		if (data.size() > size_) {
			sum_ -= data.front();
			data.pop();
		}
		return sum_ * 1.0 / data.size();
	}

private:
	queue<int> data;
	int sum_;
	int size_;
};