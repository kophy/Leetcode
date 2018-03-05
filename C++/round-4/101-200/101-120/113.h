class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		unordered_map<TreeNode *, TreeNode *> parent;
		if (root != nullptr) {
			parent[root] = nullptr;
			dfs(result, root, parent, sum);
		}
		return result;
	}

private:
	void dfs(vector<vector<int>> &result, TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent, int sum) {
		sum -= root->val;

		if (root->left == nullptr && root->right == nullptr) {
			if (sum == 0) {
				vector<int> path;
				for (TreeNode *temp = root; temp != nullptr; temp = parent[temp])
					path.push_back(temp->val);
				reverse(path.begin(), path.end());
				result.push_back(path);
			}
			return;
		}
		if (root->left != nullptr) {
			parent[root->left] = root;
			dfs(result, root->left, parent, sum);
		}
		if (root->right != nullptr) {
			parent[root->right] = root;
			dfs(result, root->right, parent, sum);
		}
	}
};