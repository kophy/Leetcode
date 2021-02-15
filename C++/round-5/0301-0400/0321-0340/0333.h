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
  int largestBSTSubtree(TreeNode *root) {
    int max_size = 0;
    helper(root, max_size);
    return max_size;
  }

 private:
  int helper(TreeNode *root, int &max_size) {
    if (root == nullptr) {
      return 0;
    }
    int left_size = helper(root->left, max_size);
    int right_size = helper(root->right, max_size);
    if (left_size == -1 || right_size == -1) {
      return -1;
    }
    if (left_size > 0) {
      auto node = root->left;
      while (node->right != nullptr) {
        node = node->right;
      }
      if (node->val >= root->val) {
        return -1;
      }
    }
    if (right_size > 0) {
      auto node = root->right;
      while (node->left != nullptr) {
        node = node->left;
      }
      if (node->val <= root->val) {
        return -1;
      }
    }
    int size = left_size + right_size + 1;
    max_size = max(max_size, size);
    return size;
  }
};