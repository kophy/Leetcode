class FreqStack {
 public:
  FreqStack() { max_freq = 0; }

  void push(int x) {
    int freq = ++num2freq[x];
    freq2nums[freq].push(x);
    max_freq = max(max_freq, freq);
  }

  int pop() {
    stack<int> &nums = freq2nums[max_freq];
    int x = nums.top();
    --num2freq[x];
    nums.pop();
    if (nums.empty()) {
      freq2nums.erase(max_freq);
      --max_freq;
    }
    return x;
  }

 private:
  int max_freq;
  unordered_map<int, int> num2freq;
  map<int, stack<int>> freq2nums;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
