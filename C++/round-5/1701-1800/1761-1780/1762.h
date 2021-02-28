class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {
    vector<int> result;
    int max_height = 0;
    for (int i = (int)heights.size() - 1; i >= 0; --i) {
      if (max_height < heights[i]) {
        result.push_back(i);
      }
      max_height = max(max_height, heights[i]);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};