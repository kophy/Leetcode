class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> count;
    for (int num : nums) {
      ++count[num];
    }
    vector<pair<int, int>> num_to_count(count.begin(), count.end());
    sort(num_to_count.begin(), num_to_count.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
           return a.second > b.second;
         });
    vector<int> result;
    for (int i = 0; i < k; ++i) {
      result.push_back(num_to_count[i].first);
    }
    return result;
  }
};