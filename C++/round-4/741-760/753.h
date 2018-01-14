class Solution {
 public:
  string crackSafe(int n, int k) {
    string result(n, '0');
    unordered_set<string> visited;
    visited.insert(result);
    dfs(result, visited, k, n);
    return result;
  }

 private:
  bool dfs(string &result, unordered_set<string> &visited, int k, int n) {
    if (visited.size() == pow(k, n)) return true;
    string prefix = result.substr(result.size() - n + 1);
    for (int i = 0; i < k; ++i) {
      string curr = prefix + to_string(i);
      if (visited.count(curr)) continue;
      visited.insert(curr);
      result.push_back(i + '0');
      if (dfs(result, visited, k, n)) return true;
      visited.erase(curr);
      result.pop_back();
    }
    return false;
  }
};
