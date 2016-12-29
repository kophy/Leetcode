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
            generatePaths(result, root, "");
        return result;
    }

private:
    void generatePaths(vector<string> &result, TreeNode *root, string temp) {
        if (temp != "")
            temp += "->";
        temp += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            result.push_back(temp);
            return;
        }
        if (root->left)
            generatePaths(result, root->left, temp);
        if (root->right)
            generatePaths(result, root->right, temp);
    }
};