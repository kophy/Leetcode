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
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<int, vector<pair<int, int>>> data;
    traverse(data, root, 0, 0);
    vector<vector<int>> result;
    for (auto &d : data) {
      sort(d.second.begin(), d.second.end(),
           [](const pair<int, int> &p1, const pair<int, int> &p2) -> bool {
             return (p1.first > p2.first) ||
                    (p1.first == p2.first && p1.second < p2.second);
           });
      result.push_back(vector<int>());
      for (const auto &p : d.second) {
        result.back().push_back(p.second);
      }
    }
    return result;
  }

 private:
  void traverse(map<int, vector<pair<int, int>>> &data, TreeNode *root, int x,
                int y) {
    if (root == nullptr) {
      return;
    }
    data[x].push_back(make_pair(y, root->val));
    traverse(data, root->left, x - 1, y - 1);
    traverse(data, root->right, x + 1, y - 1);
  }
};
