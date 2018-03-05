class Solution {
 public:
  int maxChunksToSorted(vector<int> &arr) {
    int N = arr.size();
    vector<int> leftmax(arr.size(), INT_MIN);
    leftmax[0] = arr[0];
    for (int i = 1; i < arr.size(); ++i)
      leftmax[i] = max(leftmax[i - 1], arr[i]);
    vector<int> rightmin(arr.size(), INT_MAX);
    rightmin[N - 1] = arr[N - 1];
    for (int i = N - 2; i >= 0; --i) rightmin[i] = min(rightmin[i + 1], arr[i]);

    int result = 0;
    for (int i = 0; i < N - 1; ++i)
      if (leftmax[i] <= rightmin[i + 1]) ++result;
    return result + 1;
  }
};
