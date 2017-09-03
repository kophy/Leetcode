class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                TreeNode *temp = root;
                root = (root->left == nullptr)? root->right : root->left;
                delete temp;
            } else {
                TreeNode *temp = root->left;
                while (temp->right != nullptr)
                    temp = temp->right;
                swap(root->val, temp->val);
                root->left = deleteNode(root->left, key);
            }
        }
        return root;
    }
};