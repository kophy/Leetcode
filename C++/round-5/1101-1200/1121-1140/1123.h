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
  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    int max_depth = 0;
    return helper(root, max_depth);
  }

private:
  TreeNode *helper(TreeNode *root, int &depth) {
    if (root == nullptr) {
      depth = 0;
      return nullptr;
    }
    int left_depth = 0, right_depth = 0;
    TreeNode *left = helper(root->left, left_depth);
    TreeNode *right = helper(root->right, right_depth);
    if (left_depth > right_depth) {
      depth = left_depth + 1;
      return left;
    } else if (left_depth < right_depth) {
      depth = right_depth + 1;
      return right;
    } else {
      depth = left_depth + 1;
      return root;
    }
  }
};
