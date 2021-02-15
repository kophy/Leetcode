class MovingAverage {
 public:
  /** Initialize your data structure here. */
  MovingAverage(int size) {
    size_ = size;
    sum_ = 0;
  }

  double next(int val) {
    window_.push_back(val);
    sum_ += val;
    if (window_.size() > size_) {
      sum_ -= window_.front();
      window_.pop_front();
    }
    return sum_ / window_.size();
  }

 private:
  deque<int> window_;
  double sum_;
  int size_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */