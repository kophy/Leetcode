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
        vector<string> result;
        if (root)
            search(result, root, "");
        return result;
    }

private:
    void search(vector<string> &result, TreeNode *root, string path) {
        path += "->" + to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            result.push_back(path.substr(2));
            return;
        }
        if (root->left)
            search(result, root->left, path);
        if (root->right)
            search(result, root->right, path);
    }
};