class Solution {
 public:
  vector<int> decode(vector<int>& encoded, int first) {
    int element = first;
    vector<int> result(1, element);
    for (int x : encoded) {
      element ^= x;
      result.push_back(element);
    }
    return result;
  }
};