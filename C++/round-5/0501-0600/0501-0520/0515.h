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
  vector<int> largestValues(TreeNode *root) {
    vector<int> result;
    helper(root, 0, result);
    return result;
  }

 private:
  void helper(TreeNode *root, int depth, vector<int> &result) {
    if (root == nullptr) {
      return;
    }
    if (result.size() == depth) {
      result.push_back(root->val);
    } else {
      result[depth] = max(result[depth], root->val);
    }
    helper(root->left, depth + 1, result);
    helper(root->right, depth + 1, result);
  }
};