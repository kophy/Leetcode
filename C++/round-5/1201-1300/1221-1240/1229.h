class Solution {
public:
  vector<int> minAvailableDuration(vector<vector<int>> &slots1,
                                   vector<vector<int>> &slots2, int duration) {
    auto f = [](const vector<int> &s1, const vector<int> &s2) -> bool {
      return s1[0] < s2[0];
    };
    sort(slots1.begin(), slots1.end(), f);
    sort(slots2.begin(), slots2.end(), f);
    int i = 0, j = 0;
    while (i < slots1.size() && j < slots2.size()) {
      if (slots1[i][0] >= slots2[j][1]) {
        ++j;
      } else if (slots1[i][1] <= slots2[j][0]) {
        ++i;
      } else {
        int begin = max(slots1[i][0], slots2[j][0]);
        int end = min(slots1[i][1], slots2[j][1]);
        if (end - begin >= duration) {
          return {begin, begin + duration};
        }
        ++i;
      }
    }
    return {};
  }
};