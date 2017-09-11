class Solution {
public:
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		TreeNode dummy(0);
		dummy.left = root;
		dfs(&dummy, v, d, 0);
		return dummy.left;
	}

private:
	void dfs(TreeNode* root, int v, int d, int curr_depth) {
		if (!root || curr_depth >= d)
			return;
		if (curr_depth == d - 1) {
			TreeNode *l = new TreeNode(v);
			l->left = root->left;
			root->left = l;
			TreeNode *r = new TreeNode(v);
			r->right = root->right;
			root->right = r;
			return;
		}
		dfs(root->left, v, d, curr_depth + 1);
		dfs(root->right, v, d, curr_depth + 1);
	}
};