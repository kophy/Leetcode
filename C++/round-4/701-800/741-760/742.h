class Solution {
 public:
  int findClosestLeaf(TreeNode *root, int k) {
    unordered_map<int, vector<int>> graph;
    unordered_set<int> leaves;
    makeGraph(root, graph, leaves);

    queue<int> data;
    unordered_set<int> visited;
    data.push(k);
    visited.insert(k);

    while (!data.empty()) {
      int curr = data.front();
      data.pop();
      if (leaves.count(curr)) return curr;
      for (int next : graph[curr]) {
        if (visited.count(next)) continue;
        data.push(next);
        visited.insert(next);
      }
    }
    return -1;
  }

 private:
  void makeGraph(TreeNode *root, unordered_map<int, vector<int>> &graph,
                 unordered_set<int> &leaves) {
    queue<TreeNode *> data;
    unordered_set<TreeNode *> visited;
    data.push(root);

    while (!data.empty()) {
      auto curr = data.front();
      data.pop();
      if (curr->left) {
        graph[curr->val].push_back(curr->left->val);
        graph[curr->left->val].push_back(curr->val);
        data.push(curr->left);
      }
      if (curr->right) {
        graph[curr->val].push_back(curr->right->val);
        graph[curr->right->val].push_back(curr->val);
        data.push(curr->right);
      }
      if (!curr->left && !curr->right) leaves.insert(curr->val);
    }
  }
};
