class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		string path = "";
		dfs(result, root, path);
		return result;
	}

private:
	void dfs(vector<string> &result, TreeNode *root, string path) {
		if (!root)
			return;
		path += to_string(root->val);
		if (!root->left && !root->right) {
			result.push_back(path);
		} else {
			path += "->";
			dfs(result, root->left, path);
			dfs(result, root->right, path);
		}
	}
};