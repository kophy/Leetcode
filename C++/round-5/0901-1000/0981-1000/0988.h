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
  string smallestFromLeaf(TreeNode *root) {
    string result;
    traverse(result, root, "");
    return result;
  }

 private:
  void traverse(string &result, TreeNode *root, string path) {
    if (root == nullptr) {
      return;
    }
    path = string(1, 'a' + root->val) + path;
    if (root->left == nullptr && root->right == nullptr) {
      result = result.empty() ? path : min(result, path);
    }
    traverse(result, root->left, path);
    traverse(result, root->right, path);
  }
};
