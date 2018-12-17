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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves1 = getLeaves(root1);
    vector<int> leaves2 = getLeaves(root2);
    return leaves1 == leaves2;
  }

 private:
  vector<int> getLeaves(TreeNode* root) {
    vector<int> leaves;
    stack<TreeNode*> data;
    data.push(root);
    while (!data.empty()) {
      auto node = data.top();
      data.pop();
      if (node->left == nullptr && node->right == nullptr) {
        leaves.push_back(node->val);
      }
      if (node->right != nullptr) {
        data.push(node->right);
      }
      if (node->left != nullptr) {
        data.push(node->left);
      }
    }
    return leaves;
  }
};
