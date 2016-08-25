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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        pathSum_helper(result, root, sum, path);
        return result;
    }
private:
    void pathSum_helper(vector<vector<int>> &result, TreeNode *root, int sum, vector<int> path) {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (accumulate(path.begin(), path.end(), 0) == sum)
                result.push_back(path);
        } else {
            pathSum_helper(result, root->left, sum, path);
            pathSum_helper(result, root->right, sum, path);
        }
    }
};