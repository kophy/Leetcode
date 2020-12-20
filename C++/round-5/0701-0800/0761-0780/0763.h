class Solution {
public:
  vector<int> partitionLabels(string S) {
    unordered_map<char, int> last_index;
    for (int i = S.size() - 1; i >= 0; --i) {
      if (last_index.count(S[i])) {
        continue;
      }
      last_index[S[i]] = i;
    }

    vector<int> result;
    int begin = 0, lower_bound = last_index[S[0]];
    for (int i = 0; i < S.size(); ++i) {
      lower_bound = max(lower_bound, last_index[S[i]]);
      if (i == lower_bound) {
        result.push_back(i - begin + 1);
        begin = i + 1;
      }
    }
    return result;
  }
};