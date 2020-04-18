class Solution {
 public:
  vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos,
                                        vector<vector<int>> &friends, int id,
                                        int level) {
    vector<int> level_friends = {id};
    unordered_set<int> visited = {id};
    for (int i = 0; i < level; ++i) {
      vector<int> temp;
      for (int i : level_friends) {
        for (int f : friends[i]) {
          if (visited.count(f)) {
            continue;
          }
          visited.insert(f);
          temp.push_back(f);
        }
      }
      level_friends = std::move(temp);
    }

    unordered_map<string, int> count;
    for (int i : level_friends) {
      for (const string &v : watchedVideos[i]) {
        ++count[v];
      }
    }
    vector<pair<string, int>> data(count.begin(), count.end());
    std::sort(
        data.begin(), data.end(),
        [](const pair<string, int> &a, const pair<string, int> &b) -> bool {
          if (a.second != b.second) {
            return a.second < b.second;
          }
          return a.first < b.first;
        });
    vector<string> result;
    for (const auto &p : data) {
      result.push_back(p.first);
    }
    return result;
  }
};