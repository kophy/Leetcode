class Solution {
 public:
  int openLock(vector<string> &deadends, string target) {
    unordered_set<string> deadends_dict(deadends.begin(), deadends.end());
    if (deadends_dict.count("0000")) return -1;

    queue<string> data;
    data.push("0000");
    unordered_set<string> visited;
    visited.insert("0000");

    int step = 0;
    while (!data.empty()) {
      queue<string> next;
      while (!data.empty()) {
        string s = data.front();
        data.pop();
        for (string &t : getNeighbors(s)) {
          if (deadends_dict.count(t) || visited.count(t)) continue;
          if (t == target) return step + 1;
          next.push(t);
          visited.insert(t);
        }
      }
      data = move(next);
      ++step;
    }
    return -1;
  }

 private:
  vector<string> getNeighbors(string &s) {
    vector<string> neighbors;
    for (int pos = 0; pos < 4; ++pos) {
      string temp = s;
      temp[pos] = '0' + (s[pos] - '0' + 1) % 10;
      neighbors.push_back(temp);
      temp[pos] = '0' + (s[pos] - '0' + 9) % 10;
      neighbors.push_back(temp);
    }
    return neighbors;
  }
};
