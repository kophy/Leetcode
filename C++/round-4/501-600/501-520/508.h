class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> sum_count;
        sumAndRecord(sum_count, root);
        
        int max_count = 1;
        for (auto &p : sum_count)
            max_count = max(max_count, p.second);
        vector<int> result;
        for (auto &p : sum_count)
            if (p.second == max_count)
                result.push_back(p.first);
        return result;
    }
    
private:
    int sumAndRecord(unordered_map<int, int> &sum_count, TreeNode *root) {
        if (!root)
            return 0;
        int sum = sumAndRecord(sum_count, root->left) + root->val + sumAndRecord(sum_count, root->right);
        ++sum_count[sum];
        return sum;
    }
};