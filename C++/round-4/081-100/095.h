class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return (n == 0)? vector<TreeNode *>() : generateTrees(1, n);
    }
    
private:
    vector<TreeNode *> generateTrees(int b, int e) {
        if (b > e)
            return {nullptr};
        vector<TreeNode *> result;
        for (int val = b; val <= e; ++val) {
            vector<TreeNode *> left_subtrees  = generateTrees(b, val - 1);
            vector<TreeNode *> right_subtrees = generateTrees(val + 1, e);
            for (auto &left : left_subtrees) {
                for (auto &right : right_subtrees) {
                    TreeNode *root = new TreeNode(val);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};