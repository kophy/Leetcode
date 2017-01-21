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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root != nullptr)
            dfs(result, root, 0);
        return result;
    }
    
private:
    void dfs(vector<vector<int>> &result, TreeNode *root, int level) {
        if (result.size() == level)
            result.push_back(vector<int>());
        result[level].push_back(root->val);
        if (root->left)
            dfs(result, root->left, level + 1);
        if (root->right)
            dfs(result, root->right, level + 1);
    }
};