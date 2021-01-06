class Solution {
 public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
         [](vector<int> &a, vector<int> &b) -> bool { return a[1] > b[1]; });

    int max_units = 0;
    for (int i = 0; i < boxTypes.size() && truckSize > 0; ++i) {
      max_units += min(boxTypes[i][0], truckSize) * boxTypes[i][1];
      truckSize -= boxTypes[i][0];
    }
    return max_units;
  }
};