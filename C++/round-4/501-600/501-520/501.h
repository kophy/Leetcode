class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        unordered_map<int, int> count;
        traverse(count, root);
        vector<pair<int, int>> data(count.begin(), count.end());
        int max_count = 0;
        for (auto &p : data)
            max_count = max(max_count, p.second);
        vector<int> result;
        for (auto &p : data)
            if (p.second == max_count)
                result.push_back(p.first);
        return result;
    }
    
private:
    void traverse(unordered_map<int, int> &count, TreeNode *root) {
        if (!root)
            return;
        ++count[root->val];
        traverse(count, root->left);
        traverse(count, root->right);
    }
};