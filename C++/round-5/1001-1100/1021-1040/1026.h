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
  int maxAncestorDiff(TreeNode *root) {
    int result = 0;
    if (root != nullptr) {
      maxAncestorDiff(root, result);
    }
    return result;
  }

 private:
  pair<int, int> maxAncestorDiff(TreeNode *root, int &result) {
    if (root->left == nullptr && root->right == nullptr) {
      return make_pair(root->val, root->val);
    }
    auto children_range = make_pair(INT_MAX, INT_MIN);
    if (root->left != nullptr) {
      auto left_range = maxAncestorDiff(root->left, result);
      children_range.first = min(children_range.first, left_range.first);
      children_range.second = max(children_range.second, left_range.second);
    }
    if (root->right != nullptr) {
      auto right_range = maxAncestorDiff(root->right, result);
      children_range.first = min(children_range.first, right_range.first);
      children_range.second = max(children_range.second, right_range.second);
    }
    result = max(result, max(abs(root->val - children_range.first),
                             abs(root->val - children_range.second)));
    children_range.first = min(children_range.first, root->val);
    children_range.second = max(children_range.second, root->val);
    return children_range;
  }
};
