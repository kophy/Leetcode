class Solution {
 public:
  int numSpecialEquivGroups(vector<string> &A) {
    unordered_set<string> result;
    for (auto &s : A) {
      result.insert(standardForm(s));
    }
    return result.size();
  }

 private:
  string standardForm(const string &s) {
    vector<string> v(2);
    for (int i = 0; i < s.size(); ++i) {
      v[i % 2].push_back(s[i]);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    return v[0] + v[1];
  }
};
