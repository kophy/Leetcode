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
  int sumRootToLeaf(TreeNode *root) {
    int sum = 0;
    sumRootToLeafHelper(sum, root, 0);
    return sum;
  }

private:
  void sumRootToLeafHelper(int &sum, TreeNode *root, int number) {
    if (root == nullptr) {
      return;
    }
    number = number * 2 + root->val;
    if (root->left == nullptr && root->right == nullptr) {
      sum += number;
      return;
    }
    sumRootToLeafHelper(sum, root->left, number);
    sumRootToLeafHelper(sum, root->right, number);
  }
};
