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
        if (root)
            search(result, root, sum, path, 0);
        return result;
    }

private:
    /* backtracking all possible paths */
    void search(vector<vector<int>> &result, TreeNode *root, int sum, vector<int> path, int curr_sum) {
        curr_sum += root->val;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (curr_sum == sum)
                result.push_back(path);
            return;
        }
        if (root->left)
            search(result, root->left, sum, path, curr_sum);
        if (root->right)
            search(result, root->right, sum, path, curr_sum);
    }
};