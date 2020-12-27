// Brute force.
class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    if (heights.empty() || heights[0].empty()) {
      return 0;
    }
    M = heights.size();
    N = heights[0].size();

    return helper(heights, 0, 0);
  }

 private:
  int M, N;
  int di[4] = {-1, 0, 1, 0};
  int dj[4] = {0, -1, 0, 1};

  int helper(vector<vector<int>>& heights, int i, int j) {
    if (i == M - 1 && j == N - 1) {
      return 0;
    }

    int current_height = heights[i][j];
    heights[i][j] = INT_MAX;
    int effort = INT_MAX;

    for (int k = 0; k < 4; ++k) {
      int ni = i + di[k], nj = j + dj[k];
      if (!isValid(ni, nj) || heights[ni][nj] == INT_MAX) {
        continue;
      }
      int rest = helper(heights, ni, nj);
      if (rest >= 0) {
        effort = min(effort, max(abs(current_height - heights[ni][nj]), rest));
      }
    }

    heights[i][j] = current_height;
    return (effort == INT_MAX) ? -1 : effort;
  }

  bool isValid(int i, int j) { return i >= 0 && i < M && j >= 0 && j < N; }
};