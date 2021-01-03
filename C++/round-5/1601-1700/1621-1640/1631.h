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

// Prim Algorithm
struct Edge {
  int node1_;
  int node2_;
  int effort_;

  Edge(int node1, int node2, int effort) {
    node1_ = node1;
    node2_ = node2;
    effort_ = effort;
  }
};

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    if (heights.empty() || heights[0].empty()) {
      return 0;
    }
    M = heights.size();
    N = heights[0].size();

    // Get all edges and sort them by effort.
    vector<Edge> edges;
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, -1, 0, 1};
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < 4; ++k) {
          int ni = i + di[k], nj = j + dj[k];
          if (!isValid(ni, nj)) {
            continue;
          }
          Edge e(getIndex(i, j), getIndex(ni, nj),
                 abs(heights[i][j] - heights[ni][nj]));
          edges.push_back(e);
        }
      }
    }
    sort(edges.begin(), edges.end(),
         [](const Edge& e1, const Edge& e2) -> bool {
           return e1.effort_ < e2.effort_;
         });

    // Prim algorithm with union-find set.
    int result = 0;
    vector<int> labels(M * N, 0);
    for (int i = 0; i < labels.size(); ++i) {
      labels[i] = i;
    }
    for (const auto& e : edges) {
      result = e.effort_;
      unionLabels(labels, e.node1_, e.node2_);
      if (getLabel(labels, 0) == getLabel(labels, M * N - 1)) {
        break;
      }
    }
    return result;
  }

 private:
  int M, N;

  bool isValid(int i, int j) { return i >= 0 && i < M && j >= 0 && j < N; }

  int getIndex(int i, int j) { return i * N + j; }

  int getLabel(vector<int>& labels, int i) {
    if (labels[i] != i) {
      labels[i] = getLabel(labels, labels[i]);
    }
    return labels[i];
  }

  void unionLabels(vector<int>& labels, int i, int j) {
    labels[getLabel(labels, i)] = getLabel(labels, j);
  }
};