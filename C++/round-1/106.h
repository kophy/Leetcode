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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty())
            return NULL;
        
        reverse(postorder.begin(), postorder.end());
        reverse(inorder.begin(), inorder.end());
		
        TreeNode* root = new TreeNode(postorder[0]);
        stack<TreeNode*> data;
        data.push(root);
        int index = 0;
        
        for (int i = 1; i < postorder.size(); ++i) {
            TreeNode *curr = data.top();
            if (data.top()->val != inorder[index]) {
                curr->right = new TreeNode(postorder[i]);
                data.push(curr->right);
            } else {
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