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
  TreeNode *balanceBST(TreeNode *root) {
    vector<int> elements;
    inorderTraversal(root, elements);
    return buildBST(elements, 0, elements.size() - 1);
  }

 private:
  void inorderTraversal(TreeNode *root, vector<int> &elements) {
    if (root == nullptr) {
      return;
    }
    inorderTraversal(root->left, elements);
    elements.push_back(root->val);
    inorderTraversal(root->right, elements);
  }

  TreeNode *buildBST(vector<int> &elements, int begin, int end) {
    if (begin > end) {
      return nullptr;
    }
    int mid = (begin + end) / 2;
    TreeNode *root = new TreeNode(elements[mid]);
    root->left = buildBST(elements, begin, mid - 1);
    root->right = buildBST(elements, mid + 1, end);
    return root;
  }
};