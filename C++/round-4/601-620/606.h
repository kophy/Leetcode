class Solution {
public:
    string tree2str(TreeNode *t) {
        if (!t)
            return "";
        string result = to_string(t->val);
        if (t->left || t->right)
            result += "(" + tree2str(t->left) + ")";
        if (t->right)
            result += "(" + tree2str(t->right) + ")";
        return result;
    }
};