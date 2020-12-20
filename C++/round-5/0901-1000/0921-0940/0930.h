class Solution {
public:
  int numSubarraysWithSum(vector<int> &A, int S) {
    int result = 0, sum = 0;
    unordered_map<int, int> prefix_to_count;
    prefix_to_count[0] = 1;
    for (int num : A) {
      sum += num;
      if (prefix_to_count.count(sum - S)) {
        result += prefix_to_count[sum - S];
      }
      ++prefix_to_count[sum];
    }
    return result;
  }
};
