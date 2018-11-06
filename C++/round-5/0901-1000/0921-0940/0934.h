class Solution {
 public:
  int shortestBridge(vector<vector<int>> &A) {
    if (A.empty() || A[0].empty()) {
      return 0;
    }
    M = A.size();
    N = A[0].size();
    directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // get all grids of two islands.
    unordered_set<int> island1, island2;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (island1.empty()) {
          getAllGrids(island1, A, i, j);
        } else if (!island1.count(index(i, j))) {
          getAllGrids(island2, A, i, j);
        }
      }
    }
    // "grow" one island until it reaches the other.
    for (int step = 0; step <= M + N; ++step) {
      unordered_set<int> next;
      for (int idx : island1) {
        for (int neighbor : getNeighbors(idx)) {
          if (island1.count(neighbor)) {
            continue;
          }
          if (island2.count(neighbor)) {
            return step;
          }
          next.insert(neighbor);
        }
      }
      island1.insert(next.begin(), next.end());
    }
    return 0;
  }

 private:
  int M, N;
  vector<vector<int>> directions;

  int index(int i, int j) { return i * N + j; }

  bool isValid(int i, int j) { return i >= 0 && i < M && j >= 0 && j < N; }

  void getAllGrids(unordered_set<int> &components, vector<vector<int>> &A,
                   int i, int j) {
    if (isValid(i, j) && A[i][j] == 1) {
      int idx = index(i, j);
      if (components.count(idx)) {
        return;
      }
      components.insert(idx);
      for (const auto &direction : directions) {
        getAllGrids(components, A, i + direction[0], j + direction[1]);
      }
    }
  }

  vector<int> getNeighbors(int idx) {
    vector<int> neighbors;
    for (const auto &direction : directions) {
      int ni = (idx / N) + direction[0], nj = (idx % N) + direction[1];
      if (isValid(ni, nj)) {
        neighbors.push_back(index(ni, nj));
      }
    }
    return neighbors;
  }
};
