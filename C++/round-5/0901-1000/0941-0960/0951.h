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
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) {
      return true;
    }
    if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
      return false;
    }
    if (!memo.count(root1) || !memo[root1].count(root2)) {
      memo[root1][root2] = (flipEquiv(root1->left, root2->left) &&
                            flipEquiv(root1->right, root2->right)) ||
                           (flipEquiv(root1->left, root2->right) &&
                            flipEquiv(root1->right, root2->left));
    }
    return memo[root1][root2];
  }

 private:
  unordered_map<TreeNode*, unordered_map<TreeNode*, bool>>
      memo;  // space complexity is O(N^2)
};
