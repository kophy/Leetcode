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
  double maximumAverageSubtree(TreeNode *root) {
    double result = 0;
    helper(root, result);
    return result;
  }

 private:
  pair<int, int> helper(TreeNode *root, double &result) {
    if (root == nullptr) {
      return std::make_pair(0, 0);
    }
    auto left = helper(root->left, result);
    auto right = helper(root->right, result);
    int count = left.first + right.first + 1;
    int sum = left.second + right.second + root->val;
    result = std::max(result, sum * 1.0 / count);
    return std::make_pair(count, sum);
  }
};
