class Solution {
 public:
  int maximizeSweetness(vector<int> &sweetness, int K) {
    int low = 0;
    int high = std::accumulate(sweetness.begin(), sweetness.end(), 0);
    while (low < high) {
      int mid = (low + high + 1) / 2;
      if (check(sweetness, K, mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }

 private:
  bool check(vector<int> &sweetness, int K, int threshold) {
    int count = 0;
    int current = 0;
    for (int i = 0; i < sweetness.size(); ++i) {
      current += sweetness[i];
      if (current >= threshold) {
        current = 0;
        ++count;
        if (count > K) {
          return true;
        }
      }
    }
    return false;
  }
};