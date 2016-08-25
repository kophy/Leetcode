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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root)
            path_helper(root, itoa(root->val));
        return result;
    }
private:
    vector<string> result;
    string itoa(int n) {
        stringstream ss;
        ss << n;
        return ss.str();
    }

    void path_helper(TreeNode *root, string curr) {
        if (!root->left && !root->right) {
            result.push_back(curr);
            return;
        }
        if (root->left)
            path_helper(root->left, curr + "->" + itoa(root->left->val));
        if (root->right)
            path_helper(root->right, curr + "->" + itoa(root->right->val));
    }
};