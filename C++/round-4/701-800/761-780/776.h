class Solution {
 public:
  vector<TreeNode *> splitBST(TreeNode *root, int V) {
    if (!root) return vector<TreeNode *>(2, nullptr);
    vector<TreeNode *> result;
    if (root->val <= V) {
      result = splitBST(root->right, V);
      root->right = result[0];
      result[0] = root;
    } else {
      result = splitBST(root->left, V);
      root->left = result[1];
      result[1] = root;
    }
    return result;
  }
};
