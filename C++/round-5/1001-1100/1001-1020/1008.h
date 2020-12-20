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
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    return bstFromPreorder(preorder, 0, (int)preorder.size() - 1);
  }

private:
  TreeNode *bstFromPreorder(vector<int> &preorder, int i, int j) {
    if (i > j) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[i]);
    if (i == j) {
      return root;
    }
    int k = i + 1;
    while (k <= j && preorder[k] < preorder[i]) {
      ++k;
    }
    root->left = bstFromPreorder(preorder, i + 1, k - 1);
    root->right = bstFromPreorder(preorder, k, j);
    return root;
  }
};
