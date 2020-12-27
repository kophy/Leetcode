class Solution {
 public:
  int findBestValue(vector<int>& arr, int target) {
    int low = 0, high = *max_element(arr.begin(), arr.end());
    while (low + 1 < high) {
      int mid = low + (high - low) / 2;
      int sum = getSumWithCap(arr, mid);

      if (sum < target) {
        low = mid;
      } else if (sum == target) {
        return mid;
      } else {
        high = mid;
      }
    }

    int diff_low = abs(getSumWithCap(arr, low) - target);
    int diff_high = abs(getSumWithCap(arr, high) - target);
    return diff_low <= diff_high ? low : high;
  }

 private:
  int getSumWithCap(vector<int>& arr, int cap) {
    int result = 0;
    for (int x : arr) {
      result += std::min(x, cap);
    }
    return result;
  }
};