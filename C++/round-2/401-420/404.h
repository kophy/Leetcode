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
    int sumOfLeftLeaves(TreeNode *root) {
        int result = 0;
        searchLeaf(result, root, false);
        return result;
    }

private:
    void searchLeaf(int &result, TreeNode *root, bool is_left) {
        if (!root)
            return;
        if (root->left == NULL && root->right == NULL) {
            if (is_left)
                result += root->val;
        } else {
            searchLeaf(result, root->left, true);
            searchLeaf(result, root->right, false);
        }
    }
};