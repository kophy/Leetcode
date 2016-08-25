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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode *> data;
        if (root)
            data.push_back(root);
        while (!data.empty()) {
            vector<int> curr;
            for (int i = 0; i < data.size(); ++i)
                curr.push_back(data[i]->val);
            result.push_back(curr);
            vector<TreeNode *> temp;
            for (int i = 0; i < data.size(); ++i) {
                if (data[i]->left)
                    temp.push_back(data[i]->left);
                if (data[i]->right)
                    temp.push_back(data[i]->right);
            }
            data = temp;
        }
        for (int i = 0; i < result.size() / 2; ++i)
            swap(result[i], result[result.size() - i - 1]);
        return result;
    }
};