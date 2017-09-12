class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		unordered_set<int> visited;
		return dfs(root, visited, k);
	}

private:
	bool dfs(TreeNode *root, unordered_set<int> &visited, int k) {
		if (root == NULL)
			return false;
		if (visited.count(k - root->val))
			return true;
		visited.insert(root->val);
		return dfs(root->left, visited, k) || dfs(root->right, visited, k);
	}
};