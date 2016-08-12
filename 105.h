class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty())
            return NULL;

        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> data;
        data.push(root);
        int index = 0;

        for(int i = 1; i < preorder.size(); ++i) {
            TreeNode *curr = data.top();
            if(data.top()->val != inorder[index]) {
                curr->left = new TreeNode(preorder[i]);
                data.push(curr->left);
            } else {
                while(!data.empty() && data.top()->val == inorder[index]) {
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