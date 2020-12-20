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
    if (memo.count(N)) {
      return memo[N];
    }
    vector<TreeNode *> result;
    if (N == 0) {
      result.push_back(nullptr);
    } else if (N % 2 == 1) {
      for (int i = 0; i < N; ++i) {
        vector<TreeNode *> leftSubtrees = allPossibleFBT(i);
        vector<TreeNode *> rightSubtrees = allPossibleFBT(N - i - 1);
        for (auto left : leftSubtrees) {
          for (auto right : rightSubtrees) {
            TreeNode *root = new TreeNode(0);
            root->left = left;
            root->right = right;
            result.push_back(root);
          }
        }
      }
    }
    memo[N] = result;
    return result;
  }

private:
  unordered_map<int, vector<TreeNode *>> memo;
};
