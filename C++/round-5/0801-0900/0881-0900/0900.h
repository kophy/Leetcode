class RLEIterator {
public:
  RLEIterator(vector<int> A) {
    for (int i = 0; i < A.size(); i += 2) {
      data.push(make_pair(A[i + 1], A[i]));
    }
  }

  int next(int n) {
    int result = -1;
    while (n > 0 && !data.empty()) {
      if (data.front().second >= n) {
        result = data.front().first;
        data.front().second -= n;
        n = 0;
      } else {
        n -= data.front().second;
        data.pop();
      }
    }
    return result;
  }

private:
  queue<pair<int, int>> data;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
