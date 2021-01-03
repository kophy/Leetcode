class Solution {
 public:
  double trimMean(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int padding = arr.size() * 0.05;

    double sum = 0;
    int count = 0;
    for (int i = padding; i < arr.size() - padding; ++i) {
      sum += arr[i];
      ++count;
    }
    return sum / count;
  }
};