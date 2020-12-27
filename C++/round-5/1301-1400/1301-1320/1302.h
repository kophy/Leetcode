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
  int deepestLeavesSum(TreeNode *root) {
    map<int, int> level_sums;
    traverse(root, 0, level_sums);
    return level_sums.rbegin()->second;
  }

 private:
  void traverse(TreeNode *root, int level, map<int, int> &level_sums) {
    if (root == nullptr) {
      return;
    }
    level_sums[level] += root->val;
    traverse(root->left, level + 1, level_sums);
    traverse(root->right, level + 1, level_sums);
  }
};