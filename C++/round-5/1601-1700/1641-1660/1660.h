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
  TreeNode *correctBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }

    vector<TreeNode *> nodes;
    nodes.push_back(root);
    while (!nodes.empty()) {
      unordered_set<TreeNode *> seen;
      vector<TreeNode *> next;

      for (int i = nodes.size() - 1; i >= 0; --i) {
        auto node = nodes[i];
        if (node->right != nullptr) {
          if (seen.count(node->right->right)) {
            node->right = nullptr;
            return root;
          }
          seen.insert(node->right);
          next.push_back(node->right);
        }
        if (node->left != nullptr) {
          if (seen.count(node->left->right)) {
            node->left = nullptr;
            return root;
          }
          seen.insert(node->left);
          next.push_back(node->left);
        }
      }
      nodes = std::move(next);
      reverse(nodes.begin(), nodes.end());
    }
    return root;
  }
};