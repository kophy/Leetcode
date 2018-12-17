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
  bool isCompleteTree(TreeNode *root) {
    int depth = maxDepth(root);
    vector<TreeNode *> data = {root};
    for (int i = 1; i < depth; ++i) {
      vector<TreeNode *> next;
      for (auto node : data) {
        if (node == nullptr) {
          return false;
        }
        next.insert(next.end(), {node->left, node->right});
      }
      data = std::move(next);
    }
    bool last_node = false;
    for (auto node : data) {
      if (last_node) {
        if (node != nullptr) {
          return false;
        }
      } else if (node == nullptr) {
        last_node = true;
      }
    }
    return true;
  }

 private:
  int maxDepth(TreeNode *root) {
    return (root == nullptr)
               ? 0
               : 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
