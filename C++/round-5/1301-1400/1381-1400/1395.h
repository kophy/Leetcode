class Solution {
public:
  int numTeams(vector<int> &rating) {
    map<int, int> count;
    for (int r : rating) {
      ++count[r];
    }

    int result = 0;
    for (int i = 0; i < (int)rating.size() - 2; ++i) {
      if (--count[rating[i]] == 0) {
        count.erase(rating[i]);
      }
      map<int, int> backup = count;
      for (int j = i + 1; j < (int)rating.size() - 1; ++j) {
        if (--count[rating[j]] == 0) {
          count.erase(rating[j]);
        }

        if (rating[i] < rating[j]) {
          for (auto iter = count.upper_bound(rating[j]); iter != count.end();
               ++iter) {
            result += iter->second;
          }
        } else if (rating[i] > rating[j]) {
          for (auto iter = count.begin();
               iter != count.end() && iter->first < rating[j]; ++iter) {
            result += iter->second;
          }
        }
      }
      count = std::move(backup);
    }
    return result;
  }
};