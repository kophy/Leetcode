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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode *> data;
        int direction = 0;
        if (root)
            data.push_back(root);
        while (!data.empty()) {
            vector<int> curr;
            if (direction == 0) {
                for (int j = 0; j < data.size(); ++j)
                    curr.push_back(data[j]->val);
            } else {
                for (int j = data.size() - 1; j >= 0; --j)
                    curr.push_back(data[j]->val);
            }
            direction = 1 - direction;
            result.push_back(curr);

            vector<TreeNode* > temp;
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