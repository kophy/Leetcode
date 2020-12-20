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
  TreeNode *increasingBST(TreeNode *root) {
    stack<TreeNode *> data;
    for (; root != nullptr; root = root->left) {
      data.push(root);
    }
    TreeNode dummy(0), *curr = &dummy;
    while (!data.empty()) {
      auto node = data.top();
      data.pop();
      for (auto t = node->right; t != nullptr; t = t->left) {
        data.push(t);
      }
      node->left = node->right = nullptr;
      curr->right = node;
      curr = curr->right;
    }
    return dummy.right;
  }
};
