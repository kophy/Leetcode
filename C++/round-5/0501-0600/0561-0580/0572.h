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
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (isEqualTree(s, t)) {
      return true;
    }
    if (s != nullptr) {
      return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    return false;
  }

 private:
  bool isEqualTree(TreeNode* s, TreeNode* t) {
    if (s == nullptr && t == nullptr) {
      return true;
    }
    if (s == nullptr || t == nullptr) {
      return false;
    }
    return s->val == t->val && isEqualTree(s->left, t->left) &&
           isEqualTree(s->right, t->right);
  }
};