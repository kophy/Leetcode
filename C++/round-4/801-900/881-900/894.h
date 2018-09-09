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
  vector<TreeNode *> allPossibleFBT(int N) {
    if (memo.find(N) == memo.end()) {
      vector<TreeNode *> result;
      // Full binary tree must have odd number of nodes.
      if (N == 1) {
        result.push_back(new TreeNode(0));
      } else if (N % 2 == 1) {
        for (int i = 1; i < N; i += 2) {
          for (auto left : allPossibleFBT(i)) {
            for (auto right : allPossibleFBT(N - i - 1)) {
              TreeNode *root = new TreeNode(0);
              root->left = left;
              root->right = right;
              result.push_back(root);
            }
          }
        }
      }
      memo[N] = result;
    }
    return memo[N];
  }

 private:
  unordered_map<int, vector<TreeNode *>> memo;
};
