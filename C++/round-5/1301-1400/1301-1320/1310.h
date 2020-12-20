class Solution {
public:
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); ++i) {
      prefix[i + 1] = prefix[i] ^ arr[i];
    }
    vector<int> result;
    for (const auto &query : queries) {
      result.push_back(prefix[query[0]] ^ prefix[query[1] + 1]);
    }
    return result;
  }
};
