class Solution {
public:
	int sumOfLeftLeaves(TreeNode *root) {
		int result = 0;
		sumLeftLeaves(result, root, false);
		return result;
	}

private:
	void sumLeftLeaves(int &result, TreeNode *root, bool left) {
		if (root == nullptr)
			return;
		if (root->left == nullptr && root->right == nullptr && left) {
			result += root->val;
			return;
		}
		sumLeftLeaves(result, root->left, true);
		sumLeftLeaves(result, root->right, false);
	}
};