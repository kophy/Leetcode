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
  int sumEvenGrandparent(TreeNode *root) {
    int sum = 0;
    dfs(root, false, false, sum);
    return sum;
  }

 private:
  void dfs(TreeNode *root, bool even_parent, bool even_grandparent, int &sum) {
    if (root == nullptr || visited.count(root)) {
      return;
    }
    visited.insert(root);
    if (even_grandparent) {
      sum += root->val;
    }
    bool even_node = (root->val % 2 == 0);
    dfs(root->left, even_node, even_parent, sum);
    dfs(root->right, even_node, even_parent, sum);
  }

  unordered_set<TreeNode *> visited;
};