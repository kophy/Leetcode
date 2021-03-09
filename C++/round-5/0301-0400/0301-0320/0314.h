/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    map<int, vector<int>> column_to_elements;
    queue<pair<TreeNode *, int>> nodes;
    nodes.push(make_pair(root, 0));

    while (!nodes.empty()) {
      auto [node, column] = nodes.front();
      nodes.pop();
      column_to_elements[column].push_back(node->val);
      cout << node->val << endl;
      if (node->left) {
        nodes.push(make_pair(node->left, column - 1));
      }
      if (node->right) {
        nodes.push(make_pair(node->right, column + 1));
      }
    }

    vector<vector<int>> result;
    for (auto &[_, elements] : column_to_elements) {
      result.push_back(elements);
    }
    return result;
  }
};