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
  TreeNode *bstToGst(TreeNode *root) {
    int sum = 0;
    stack<TreeNode *> data;
    for (TreeNode *node = root; node != nullptr; node = node->right) {
      data.push(node);
    }

    while (!data.empty()) {
      TreeNode *node = data.top();
      data.pop();

      int temp = node->val;
      node->val += sum;
      sum += temp;

      node = node->left;
      for (; node != nullptr; node = node->right) {
        data.push(node);
      }
    }

    return root;
  }
};