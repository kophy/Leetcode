class Solution {
public:
    int findTilt(TreeNode *root) {
        int tilt = 0;
        helper(tilt, root);
        return tilt;
    }
    
private:
    // update tilt of current node and return sum of current subtree
    int helper(int &tilt, TreeNode *root) {
        if (!root)
            return 0;
        int left = helper(tilt, root->left);
        int right = helper(tilt, root->right);
        tilt += abs(left - right);
        return left + right + root->val;
    }
};