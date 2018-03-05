class Solution {
 public:
  bool isBipartite(vector<vector<int>> &graph) {
    unordered_map<int, int> node2color;
    for (int node = 0; node < graph.size(); ++node) {
      if (!node2color.count(node)) node2color[node] = 0;
      int other_color = 1 - node2color[node];
      for (auto other : graph[node]) {
        if (!node2color.count(other)) {
          node2color[other] = other_color;
        } else {
          if (node2color[other] != other_color) return false;
        }
      }
    }
    return true;
  }
};
