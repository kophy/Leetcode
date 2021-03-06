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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderSearch(result, root, 0);
        for (int i = 1; i < result.size(); i += 2)
            reverse(result[i].begin(), result[i].end());
        return result;
    }

private:
    void levelOrderSearch(vector<vector<int>> &result, TreeNode *root, int level) {
        if (root) {
            if (level == result.size())
                result.push_back(vector<int>());
            result[level].push_back(root->val);
            levelOrderSearch(result, root->left, level + 1);
            levelOrderSearch(result, root->right, level + 1);
        }
    }
};