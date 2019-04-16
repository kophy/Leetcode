class Solution {
 public:
  int findJudge(int N, vector<vector<int>> &trust) {
    vector<int> outgoing(N + 1, 0), incoming(N + 1, 0);
    for (auto &p : trust) {
      ++outgoing[p[0]];
      ++incoming[p[1]];
    }
    for (int i = 1; i <= N; ++i) {
      if (outgoing[i] == 0 && incoming[i] == N - 1) {
        return i;
      }
    }
    return -1;
  }
};
