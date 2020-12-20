class Solution {
public:
  int totalFruit(vector<int> &tree) {
    int result = 0;
    unordered_map<int, int> count;
    for (int i = 0, j = 0; j < tree.size(); ++j) {
      ++count[tree[j]];
      while (count.size() > 2) {
        if (--count[tree[i]] == 0) {
          count.erase(tree[i]);
        }
        ++i;
      }
      result = max(result, j - i + 1);
    }
    return result;
  }
};
