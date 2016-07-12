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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root)
            return result;

        vector<TreeNode *> data;
        data.push_back(root);
        while (!data.empty()) {
            result.push_back(data[data.size() - 1]->val);
            vector<TreeNode *> temp;
            for (int i = 0; i < data.size(); ++i) {
                if (data[i]->left)
                    temp.push_back(data[i]->left);
                if (data[i]->right)
                    temp.push_back(data[i]->right);
            }
            data = temp;
        }
        return result;
    }
};