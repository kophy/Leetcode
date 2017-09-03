class Solution {
public:
	bool isValidBST(TreeNode *root) {
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}

private:
	bool isValidBST(TreeNode *root, long lower, long upper) {
		if (root == nullptr)
			return true;
		if (root->val <= lower || root->val >= upper)
			return false;
		return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
	}
};