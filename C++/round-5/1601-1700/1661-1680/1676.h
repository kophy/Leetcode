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
  TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes) {
    return helper(root, {nodes.begin(), nodes.end()});
  }

 private:
  TreeNode *helper(TreeNode *root, unordered_set<TreeNode *> nodes) {
    if (root == nullptr || nodes.count(root)) {
      return root;
    }
    TreeNode *left = helper(root->left, nodes);
    TreeNode *right = helper(root->right, nodes);

    if (left != nullptr && right != nullptr) {
      return root;
    }
    if (left != nullptr) {
      return left;
    }
    if (right != nullptr) {
      return right;
    }
    return nullptr;
  }
};