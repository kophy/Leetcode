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
        if (root)
            rightSideView_helper(result, root, 0);
        return result;
    }
    
private:
    void rightSideView_helper(vector<int> &result, TreeNode *root, int depth) {
        if (depth == result.size())
            result.push_back(root->val);
        else
            result[depth] = root->val;
        if (root->left)
            rightSideView_helper(result, root->left, depth + 1);
        if (root->right)
            rightSideView_helper(result, root->right, depth + 1);
    }
};