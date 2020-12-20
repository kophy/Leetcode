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
  int maxSumBST(TreeNode *root) {
    int max_sum = 0;
    helper(root, max_sum);
    return max_sum;
  }

private:
  pair<bool, int> helper(TreeNode *root, int &max_sum) {
    if (root == nullptr) {
      return std::make_pair(true, 0);
    }
    auto left_status = helper(root->left, max_sum);
    auto right_status = helper(root->right, max_sum);

    if (!left_status.first || !right_status.first) {
      return std::make_pair(false, 0);
    }
    if (root->left != nullptr) {
      auto curr = root->left;
      while (curr->right != nullptr) {
        curr = curr->right;
      }
      if (root->val <= curr->val) {
        return std::make_pair(false, 0);
      }
    }
    if (root->right != nullptr) {
      auto curr = root->right;
      while (curr->left != nullptr) {
        curr = curr->left;
      }
      if (root->val >= curr->val) {
        return std::make_pair(false, 0);
      }
    }

    int sum = left_status.second + root->val + right_status.second;
    max_sum = max(max_sum, sum);
    return std::make_pair(true, sum);
  }
};