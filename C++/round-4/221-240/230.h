class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		int result = 0, count = 0;
		inorderTraversal(result, root, k, count);
		return result;
	}

private:
	void inorderTraversal(int &result, TreeNode *root, int k, int &count) {
		if (root == nullptr)
			return;
		inorderTraversal(result, root->left, k, count);
		if (++count == k)
			result = root->val;
		inorderTraversal(result, root->right, k, count);
	}
};