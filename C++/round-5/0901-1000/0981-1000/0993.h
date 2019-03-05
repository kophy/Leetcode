/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  bool isCousins(TreeNode *root, int x, int y) {
    unordered_map<int, int> depth;
    unordered_map<int, int> parent;
    dfs(root, 0, depth, nullptr, parent);
    return depth[x] == depth[y] && parent[x] != parent[y];
  }

 private:
  void dfs(TreeNode *node, int depth, unordered_map<int, int> &depth_map,
           TreeNode *parent, unordered_map<int, int> &parent_map) {
    if (parent != nullptr) {
      parent_map[node->val] = parent->val;
    }
    depth_map[node->val] = depth;
    if (node->left != nullptr) {
      dfs(node->left, depth + 1, depth_map, node, parent_map);
    }
    if (node->right != nullptr) {
      dfs(node->right, depth + 1, depth_map, node, parent_map);
    }
  }
};
