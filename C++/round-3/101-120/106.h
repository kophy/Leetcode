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
    TreeNode *buildTree(vector<int> &preorder, vector<int>&inorder) {
        if (preorder.size() == 0)
            return NULL;
        int prepos = 0;
        return buildTree(preorder, prepos, inorder, 0, inorder.size() - 1);
    }
    
private:
    TreeNode *buildTree(vector<int> &preorder, int &prepos, vector<int> &inorder, int instart, int inend) {
        if (prepos >= preorder.size() || instart > inend)
            return NULL;
        int val = preorder[prepos++];
        TreeNode *root = new TreeNode(val);
        int pivot = find(inorder.begin(), inorder.end(), val) - inorder.begin();
        root->left  = buildTree(preorder, prepos, inorder, instart, pivot - 1);
        root->right = buildTree(preorder, prepos, inorder, pivot + 1, inend);
        return root;
    }
};