// version 1: top down, keep cutted
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int result = 0;
        pathSum_help(result, root, sum, 0, false);
        return result;
    }

private:
    void pathSum_help(int &result, TreeNode *root, int target, int prefix, bool cutted) {
        if (!root)
            return;
        if (prefix + root->val == target)
            ++result;
        pathSum_help(result, root->left, target, prefix + root->val, cutted);
        pathSum_help(result, root->right, target, prefix + root->val, cutted);
        
        // avoid repeated search
        if (!cutted) {
            pathSum_help(result, root->left, target, 0, true);
            pathSum_help(result, root->right, target, 0, true);
        }
    }
};

// version 2: top down, keep presum (tree path as array)
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int result = 0;
        unordered_map<int, int> presum_count;
        presum_count[0] = 1;
        pathSum_help(result, root, sum, presum_count, 0);
        return result;
    }

private:
    void pathSum_help(int &result, TreeNode *root, int target, unordered_map<int, int> &presum_count, int presum) {
        if (!root)
            return;
        int currsum = presum + root->val;
        if (presum_count.count(currsum - target))
            result += presum_count[currsum - target];
        ++presum_count[currsum];
        pathSum_help(result, root->left, target, presum_count, currsum);
        pathSum_help(result, root->right, target, presum_count, currsum);
        --presum_count[currsum];
    }
};