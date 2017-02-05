/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*  reconstruct BST from
	inorder + preorder
	inorder + postorder
	is actually mirroring each other.

 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty())
            return nullptr;

        reverse(inorder.begin(), inorder.end());
        reverse(postorder.begin(), postorder.end());
        TreeNode *root = new TreeNode(postorder[0]);

        /* the stack and index form a iterator for BST */
        stack<TreeNode *> data;
        data.push(root);
        int index = 0;

        for (int i = 1; i < postorder.size(); ++i) {
            TreeNode *curr = data.top();
            if (data.top()->val != inorder[index]) {
                curr->right = new TreeNode(postorder[i]);
                data.push(curr->right);
            } else {
                /*  find the tree node satisfying:
                    all nodes on its right and itself have been visited
                    all nodes on its left haven't been visited
                */
                while (!data.empty() && data.top()->val == inorder[index]) {
                    curr = data.top();
                    data.pop();
                    ++index;
                }
                curr->left = new TreeNode(postorder[i]);
                data.push(curr->left);
            }
        }
        return root;
    }
};