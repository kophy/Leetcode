class Solution {
public:
  int shortestPath(vector<vector<int>> &grid, int k) {
    if (grid.size() == 0 || grid[0].size() == 0) {
      return 0;
    }
    M = grid.size();
    N = grid[0].size();

    // Record the min number of obstacles to eliminate to reach (i, j).
    vector<vector<int>> min_obstacles(M, vector<int>(N, INT_MAX));
    min_obstacles[0][0] = 0;

    queue<tuple<int, int, int>> data;
    data.push(std::make_tuple(0, 0, 0));

    int step = 0;
    while (!data.empty()) {
      queue<tuple<int, int, int>> next;
      while (!data.empty()) {
        int x, y, curr_obstacles;
        std::tie(x, y, curr_obstacles) = data.front();
        data.pop();

        // 1. We're at the destination.
        if (x == M - 1 && y == N - 1) {
          return step;
        }

        // 2. Otherwise check neighbors.
        int dxs[4] = {0, -1, 0, 1};
        int dys[4] = {-1, 0, 1, 0};
        for (int l = 0; l < 4; ++l) {
          int nx = x + dxs[l], ny = y + dys[l];
          if (!isValid(nx, ny)) {
            continue;
          }
          int new_obstacles = curr_obstacles + grid[nx][ny];
          if (new_obstacles > k) {
            continue;
          }
          if (new_obstacles < min_obstacles[nx][ny]) {
            next.push(std::make_tuple(nx, ny, new_obstacles));
            min_obstacles[nx][ny] = new_obstacles;
          }
        }
      }
      data = next;
      ++step;
    }
    return -1;
  }

private:
  int M;
  int N;

  bool isValid(int x, int y) { return x >= 0 && x < M && y >= 0 && y < N; }
};