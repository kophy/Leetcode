class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return isSymmetric(root, root);
    }
    
private:
    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        return (p->val == q->val) && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};