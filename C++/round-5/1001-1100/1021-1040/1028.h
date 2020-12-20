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
  TreeNode *recoverFromPreorder(string S) {
    if (S.empty()) {
      return nullptr;
    }
    vector<pair<int, int>> data;
    int i = 0;
    while (i < S.size()) {
      int depth = 0;
      for (; i < S.size() && S[i] == '-'; ++i) {
        ++depth;
      }
      int val = 0;
      for (; i < S.size() && isdigit(S[i]); ++i) {
        val = val * 10 + (S[i] - '0');
      }
      data.push_back(make_pair(depth, val));
    }
    return recoverFromPreorder(data, 0, (int)data.size() - 1);
  }

private:
  TreeNode *recoverFromPreorder(vector<pair<int, int>> &data, int begin,
                                int end) {
    if (begin > end) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(data[begin].second);
    if (begin == end) {
      return root;
    }
    int mid = begin + 2;
    for (; mid <= end; ++mid) {
      if (data[mid].first == data[begin].first + 1) {
        break;
      }
    }
    root->left = recoverFromPreorder(data, begin + 1, mid - 1);
    root->right = recoverFromPreorder(data, mid, end);
    return root;
  }
};
