class Solution {
public:
    int largestBSTSubtree(TreeNode *root) {
        int max_count = 0;
        bool valid = true;
        largestBSTSubtree_help(max_count, valid, root);
        return max_count;
    }

private:
    int largestBSTSubtree_help(int &max_count, bool &valid, TreeNode *root) {
        // basic case 1: empty tree
        if (!root)
            return 0;
        // basic case 2: leaf node
        if (!root->left && !root->right) {
            max_count = max(max_count, 1);
            return 1;
        }

        bool left_valid = true, right_valid = true;
        int left_count = largestBSTSubtree_help(max_count, left_valid, root->left);
        int right_count = largestBSTSubtree_help(max_count, right_valid, root->right);
        // fast rejuection for non-bst trees
        if (!left_valid || !right_valid) {
            valid = false;
            return 0;
        }

        int pivot_count = 1;
        if (root->left && !root->right && maxVal(root->left) < root->val)
            pivot_count += left_count;
        else if (!root->left && root->right && minVal(root->right) > root->val)
            pivot_count += right_count;
        else if (root->left && root->right && maxVal(root->left) < root->val && minVal(root->right) > root->val)
            pivot_count += left_count + right_count;
        else
            valid = false;

        valid = valid && left_valid && right_valid;
        if (valid)
            max_count = max(max_count, pivot_count);
        return pivot_count;
    }

    int maxVal(TreeNode *root) {
        while (root->right)
            root = root->right;
        return root->val;
    }

    int minVal(TreeNode *root) {
        while (root->left)
            root = root->left;
        return root->val;
    }
};