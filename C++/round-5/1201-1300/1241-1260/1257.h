class Solution {
public:
  string findSmallestRegion(vector<vector<string>> &regions, string region1,
                            string region2) {
    unordered_map<string, string> parent;
    for (const auto &r : regions) {
      for (int i = 1; i < r.size(); ++i) {
        parent[r[i]] = r[0];
      }
    }

    vector<string> path1 = findPath(parent, region1);
    vector<string> path2 = findPath(parent, region2);

    string result = "";
    for (int i = 0; i < std::min(path1.size(), path2.size()); ++i) {
      if (path1[i] == path2[i]) {
        result = path1[i];
      } else {
        break;
      }
    }
    return result;
  }

private:
  vector<string> findPath(const unordered_map<string, string> &parent,
                          const string &region) {
    vector<string> path;
    string s = region;
    while (true) {
      path.push_back(s);
      if (!parent.count(s)) {
        break;
      }
      s = parent.at(s);
    }
    reverse(path.begin(), path.end());
    return path;
  }
};