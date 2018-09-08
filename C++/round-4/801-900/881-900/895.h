class FreqStack {
 public:
  FreqStack() { max_freq = 0; }

  void push(int x) {
    freq[x]++;
    freq2nums[freq[x]].push(x);
    max_freq = max(max_freq, freq[x]);
  }

  int pop() {
    int x = freq2nums[max_freq].top();
    freq[x]--;
    freq2nums[max_freq].pop();
    if (freq2nums[max_freq].empty()) {
      --max_freq;
    }
    return x;
  }

 private:
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> freq2nums;
  int max_freq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
