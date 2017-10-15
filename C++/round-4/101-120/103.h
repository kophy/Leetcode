class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        dfs(result, root, 0);
        for (int i = 1; i < result.size(); i += 2)
            reverse(result[i].begin(), result[i].end());
        return result;
    }
    
private:
    void dfs(vector<vector<int>> &result, TreeNode *root, int level) {
        if (!root)
            return;
        if (result.size() == level)
            result.push_back(vector<int>());
        result[level].push_back(root->val);
        dfs(result, root->left, level + 1);
        dfs(result, root->right, level + 1);
    }
};