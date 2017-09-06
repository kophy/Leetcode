class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		inorderTraversal(result, root);
		return result;
	}

private:
	void inorderTraversal(vector<int> &result, TreeNode *root) {
		if (root == nullptr)
			return;
		inorderTraversal(result, root->left);
		result.push_back(root->val);
		inorderTraversal(result, root->right);
	}
};