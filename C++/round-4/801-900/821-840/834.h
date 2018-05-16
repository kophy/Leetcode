class Solution {
 public:
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    for (auto& edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
    count = vector<int>(N, 1);
    result = vector<int>(N, 0);

    // take node 0 as the root of the tree, and use two-pass to calculate
    // distance sum. pass 1: calculate number of nodes in each subtree and
    // distance sum to subtree root.
    // pass 2: calculate distance sum to each node.
    dfs1(0, -1);
    dfs2(0, -1);
    return result;
  }

 private:
  unordered_map<int, vector<int>> neighbors;
  vector<int> count;
  vector<int> result;

  void dfs1(int node, int parent) {
    for (int child : neighbors[node]) {
      if (child != parent) {
        dfs1(child, node);
        count[node] += count[child];
        result[node] += result[child] + count[child];
      }
    }
  }

  void dfs2(int node, int parent) {
    for (int child : neighbors[node]) {
      if (child != parent) {
        // count[child] nodes take one less step, and (N - count[child]) nodes
        // take one more step.
        result[child] =
            result[node] - count[child] + (count.size() - count[child]);
        dfs2(child, node);
      }
    }
  }
};
