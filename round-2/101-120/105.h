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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);

        /* the stack and index form a iterator for BST */
        stack<TreeNode *> data;
        data.push(root);
        int index = 0;

        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode *curr = data.top();
            if (data.top()->val != inorder[index]) {
                curr->left = new TreeNode(preorder[i]);
                data.push(curr->left);
            } else {
                /*  find the tree node satisfying:
                    all nodes on its left and itself have been visited
                    all nodes on its right haven't been visited
                */
                while (!data.empty() && data.top()->val == inorder[index]) {
                    curr = data.top();
                    data.pop();
                    ++index;
                }
                curr->right = new TreeNode(preorder[i]);
                data.push(curr->right);
            }
        }

        return root;
    }
};

/*
	 4
  2    6
1  3  5  7  --> 4 2 1 3 6 5 7
*/