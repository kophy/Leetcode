class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int min_depth = INT_MAX;
		dfs(min_depth, root, 1);
		return min_depth;
	}

private:
	void dfs(int &min_depth, TreeNode *root, int depth) {
		if (root == nullptr)
			return;
		if (root->left == nullptr && root->right == nullptr) {
			min_depth = min(min_depth, depth);
		} else {
			dfs(min_depth, root->left, depth + 1);
			dfs(min_depth, root->right, depth + 1);
		}
	}
};