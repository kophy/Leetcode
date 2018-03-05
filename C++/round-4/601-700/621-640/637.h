class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<long, int>> data;
        dfs(data, root, 0);
        vector<double> result;
        for (auto &p : data)
            result.push_back(p.first * 1.0 / p.second);
        return result;
    }
    
private:
    void dfs(vector<pair<long, int>> &data, TreeNode *root, int level) {
        if (!root)
            return;
        if (data.size() == level)
            data.push_back(make_pair(0, 0));
        data[level].first += root->val;
        data[level].second += 1;
        dfs(data, root->left, level + 1);
        dfs(data, root->right, level + 1);
    }
};