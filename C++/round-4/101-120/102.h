class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		dfs(result, root, 0);
		return result;
	}

private:
	void dfs(vector<vector<int>> &result, TreeNode *root, int level) {
		if (!root)
			return;
		if (level == result.size())
			result.push_back(vector<int>());
		result[level].push_back(root->val);
		dfs(result, root->left, level + 1);
		dfs(result, root->right, level + 1);
	}
};