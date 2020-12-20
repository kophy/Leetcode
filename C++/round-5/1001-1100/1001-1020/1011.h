class Solution {
public:
  int shipWithinDays(vector<int> &weights, int D) {
    int low = *std::max_element(weights.begin(), weights.end());
    int high = std::accumulate(weights.begin(), weights.end(), 0);
    while (low < high) {
      int mid = (low + high) / 2;
      if (canShip(weights, D, mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }

private:
  bool canShip(const vector<int> &weights, int D, int capacity) {
    vector<int> orders(D, 0);
    int i = 0;
    for (int weight : weights) {
      if (orders[i] + weight > capacity) {
        ++i;
      }
      if (i >= D) {
        return false;
      }
      orders[i] += weight;
    }
    return true;
  }
};
