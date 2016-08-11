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
    vector<TreeNode *> generateTrees(int n) {
        return n? generateTrees_help(1, n) : vector<TreeNode *>();
    }

private:
    vector<TreeNode *> generateTrees_help(int begin, int end) {
        vector<TreeNode *> result;
        if (begin > end)
            result.push_back(nullptr);
        else if (begin == end)
            result.push_back(new TreeNode(begin));
        else {
            for (int i = begin; i <= end; ++i) {
                vector<TreeNode *> left = generateTrees_help(begin, i - 1);
                vector<TreeNode *> right = generateTrees_help(i + 1, end);
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        TreeNode *root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        result.push_back(root);
                    }
                }
            }
        }
        return result;
    }
};