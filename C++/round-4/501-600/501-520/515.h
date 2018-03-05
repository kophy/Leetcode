class Solution {
public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> result;
        dfs(result, root, 0);
        return result;
    }
    
private:
    void dfs(vector<int> &result, TreeNode *root, int level) {
        if (root == nullptr)
            return;
        if (result.size() <= level)
            result.push_back(root->val);
        else
            result[level] = max(result[level], root->val);
        dfs(result, root->left, level + 1);
        dfs(result, root->right, level + 1);
    }
};