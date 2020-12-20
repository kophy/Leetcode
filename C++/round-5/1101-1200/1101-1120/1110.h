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
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    unordered_set<int> delete_set(to_delete.begin(), to_delete.end());
    vector<TreeNode *> result;
    helper(root, nullptr, delete_set, result);
    return result;
  }

private:
  TreeNode *helper(TreeNode *node, TreeNode *parent,
                   unordered_set<int> &delete_set, vector<TreeNode *> &result) {
    if (node == nullptr) {
      return nullptr;
    }
    if (delete_set.count(node->val)) {
      helper(node->left, nullptr, delete_set, result);
      helper(node->right, nullptr, delete_set, result);
      return nullptr;
    } else {
      node->left = helper(node->left, node, delete_set, result);
      node->right = helper(node->right, node, delete_set, result);
      if (parent == nullptr) {
        result.push_back(node);
      }
      return node;
    }
  }
};
