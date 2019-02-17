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
  int distributeCoins(TreeNode *root) {
    int result = 0;
    dfs(result, root);
    return result;
  }

 private:
  int dfs(int &result, TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left_excess = dfs(result, root->left);
    int right_excess = dfs(result, root->right);
    result += abs(left_excess) + abs(right_excess);
    return left_excess + right_excess + root->val - 1;
  }
};
