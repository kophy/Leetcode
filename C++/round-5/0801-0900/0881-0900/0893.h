class Solution {
public:
  int numSpecialEquivGroups(vector<string> &A) {
    unordered_set<string> groups;
    for (const string &s : A) {
      groups.insert(standardForm(s));
    }
    return groups.size();
  }

private:
  string standardForm(const string &s) {
    string even, odd;
    for (int i = 0; i < s.size(); ++i) {
      if (i % 2 == 0) {
        even.push_back(s[i]);
      } else {
        odd.push_back(s[i]);
      }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    return even + odd;
  }
};
