class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode *> data;
        for (TreeNode *curr = root; curr; curr = curr->right)
            data.push(curr);
        int sum = 0;
        while (!data.empty()) {
            TreeNode *curr = data.top();
            data.pop();
            curr->val += sum;
            sum = curr->val;
            
            curr = curr->left;
            for (; curr; curr = curr->right)
                data.push(curr);
        }
        return root;
    }
};