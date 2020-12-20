class CustomStack {
public:
  CustomStack(int maxSize) { max_size = maxSize; }

  void push(int x) {
    if (data.size() < max_size) {
      data.push_back(x);
    }
  }

  int pop() {
    if (data.empty()) {
      return -1;
    }
    int result = data.back();
    data.pop_back();
    return result;
  }

  void increment(int k, int val) {
    for (int i = 0; i < k && i < data.size(); ++i) {
      data[i] += val;
    }
  }

private:
  vector<int> data;
  int max_size;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */