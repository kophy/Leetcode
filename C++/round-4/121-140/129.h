class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int result = 0;
        dfs(result, root, 0);
        return result;
    }
    
private:
    void dfs(int &result, TreeNode *root, int number) {
        if (root == nullptr)
            return;
        number = number * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            result += number;
        dfs(result, root->left, number);
        dfs(result, root->right, number);
    }
};