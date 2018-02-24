class Solution {
 public:
  int minDiffInBST(TreeNode *root) {
    stack<TreeNode *> data;
    for (; root; root = root->left) data.push(root);
    int difference = INT_MAX;
    TreeNode *last = nullptr, *curr = nullptr;
    while (!data.empty()) {
      curr = data.top();
      data.pop();
      if (last) difference = min(difference, curr->val - last->val);
      last = curr;
      curr = curr->right;
      for (; curr; curr = curr->left) data.push(curr);
    }
    return difference;
  }
};
