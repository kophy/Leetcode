class RLEIterator {
 public:
  RLEIterator(vector<int> A) {
    for (int i = 0; i + 1 < A.size(); i += 2) {
      if (A[i] > 0) {
        data.push(make_pair(A[i + 1], A[i]));
      }
    }
  }

  int next(int n) {
    int val = -1;
    while (!data.empty() && n > 0) {
      if (n > data.front().second) {
        n -= data.front().second;
        data.pop();
      } else {
        val = data.front().first;
        data.front().second -= n;
        n = 0;
      }
    }
    return (n == 0) ? val : -1;
  }

 private:
  queue<pair<int, int>> data;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
