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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root)
            search(sum, 0, root);
        return sum;
    }

private:
    void search(int &sum, int temp, TreeNode *root) {
        temp = temp * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += temp;
            return;
        }
        if (root->left)
            search(sum, temp, root->left);
        if (root->right)
            search(sum, temp, root->right);
    }
};