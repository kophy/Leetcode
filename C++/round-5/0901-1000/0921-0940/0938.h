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
  int rangeSumBST(TreeNode *root, int L, int R) {
    int result = 0;
    rangeSumBSTHelper(result, root, L, R);
    return result;
  }

 private:
  void rangeSumBSTHelper(int &result, TreeNode *root, int L, int R) {
    if (root == nullptr) {
      return;
    }
    if (root->val < L) {
      rangeSumBSTHelper(result, root->right, L, R);
    } else if (root->val > R) {
      rangeSumBSTHelper(result, root->left, L, R);
    } else {
      result += root->val;
      rangeSumBSTHelper(result, root->left, L, R);
      rangeSumBSTHelper(result, root->right, L, R);
    }
  }
};
