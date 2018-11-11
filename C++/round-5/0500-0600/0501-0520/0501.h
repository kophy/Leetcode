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
  vector<int> findMode(TreeNode* root) {
    curr_count = 0;
    max_count = 0;
    inorderTraversal(root);
    return modes;
  }

 private:
  vector<int> modes;
  int last_elem;
  int curr_count, max_count;

  void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    inorderTraversal(root->left);

    // special case: leftmost node
    if (max_count == 0) {
      curr_count = 1;
      max_count = 1;
      modes = {root->val};
    } else {
      curr_count = (root->val == last_elem) ? curr_count + 1 : 1;
      if (curr_count == max_count) {
        modes.push_back(root->val);
      } else if (curr_count > max_count) {
        max_count = curr_count;
        modes = {root->val};
      }
    }
    last_elem = root->val;

    inorderTraversal(root->right);
  }
};
