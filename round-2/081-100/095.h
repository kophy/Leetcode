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
        vector<TreeNode *> result;
        if (n > 0)
            result = generate(1, n);
        return result;
    }

private:
    vector<TreeNode *> generate(int begin, int end) {
        vector<TreeNode *> result;
        if (begin > end)
            result.push_back(NULL);
        else if (begin == end)
            result.push_back(new TreeNode(begin));
        else if (begin < end) {
            for (int i = begin; i <= end; ++i) {
                /* divide and conquer */
				vector<TreeNode *> left = generate(begin, i - 1);
                vector<TreeNode *> right = generate(i + 1, end);
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