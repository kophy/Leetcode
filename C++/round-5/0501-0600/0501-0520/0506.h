class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &nums) {
    vector<pair<int, int>> nums_with_indices;
    for (int i = 0; i < nums.size(); ++i) {
      nums_with_indices.push_back(std::make_pair(nums[i], i));
    }
    std::sort(nums_with_indices.begin(), nums_with_indices.end(),
              [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
                return a.first > b.first;
              });
    vector<string> result(nums.size(), "");
    vector<string> winners = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    for (int i = 0; i < nums_with_indices.size(); ++i) {
      int index = nums_with_indices[i].second;
      if (i < 3) {
        result[index] = winners[i];
      } else {
        result[index] = std::to_string(i + 1);
      }
    }
    return result;
  }
};
