class Solution {
 public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    map<int, int> data;
    int count = 0;
    for (int day = 0; day < apples.size() || !data.empty(); ++day) {
      // Add new apples.
      if (day < apples.size()) {
        data[day + days[day]] += apples[day];
      }
      // Remove all rotten apples.
      while (!data.empty() && data.begin()->first <= day) {
        data.erase(data.begin()->first);
      }
      if (data.empty()) {
        continue;
      }
      ++count;
      int d = data.begin()->first;
      if (--data[d] == 0) {
        data.erase(d);
      }
    }
    return count;
  }
};