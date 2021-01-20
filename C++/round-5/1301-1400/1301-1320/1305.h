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

class TreeIterator {
 public:
  TreeIterator(TreeNode* root) {
    while (root != nullptr) {
      data.push(root);
      root = root->left;
    }
  }

  int get() { return data.top()->val; }

  bool empty() { return data.empty(); }

  void move_forward() {
    auto node = data.top()->right;
    data.pop();
    while (node != nullptr) {
      data.push(node);
      node = node->left;
    }
  }

 private:
  stack<TreeNode*> data;
};

class Solution {
 public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    TreeIterator ti1(root1);
    TreeIterator ti2(root2);

    vector<int> result;
    while (!ti1.empty() && !ti2.empty()) {
      if (ti1.get() < ti2.get()) {
        result.push_back(ti1.get());
        ti1.move_forward();
      } else {
        result.push_back(ti2.get());
        ti2.move_forward();
      }
    }

    while (!ti1.empty()) {
      result.push_back(ti1.get());
      ti1.move_forward();
    }

    while (!ti2.empty()) {
      result.push_back(ti2.get());
      ti2.move_forward();
    }

    return result;
  }
};