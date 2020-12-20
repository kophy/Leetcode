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
  bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
    unordered_set<int> elems1, elems2;
    traverse(root1, elems1);
    traverse(root2, elems2);
    for (int x : elems1) {
      if (elems2.count(target - x)) {
        return true;
      }
    }
    return false;
  }

private:
  void traverse(TreeNode *root, unordered_set<int> &elems) {
    if (root == nullptr) {
      return;
    }
    traverse(root->left, elems);
    elems.insert(root->val);
    traverse(root->right, elems);
  }
};