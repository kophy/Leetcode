class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		vector<pair<int, int>> minmax_indices;
		dfs(minmax_indices, root, 0, 0);
		int max_width = 0;
		for (auto &p : minmax_indices)
			max_width = max(max_width, p.second - p.first + 1);
		return max_width;
	}

private:
	void dfs(vector<pair<int, int>> &minmax_indices, TreeNode *root, int depth, int index) {
		if (root == nullptr)
			return;
		if (minmax_indices.size() == depth)
			minmax_indices.push_back(make_pair(index, index));
		else {
			minmax_indices[depth].first = min(minmax_indices[depth].first, index);
			minmax_indices[depth].second = max(minmax_indices[depth].second, index);
		}
		dfs(minmax_indices, root->left, depth + 1, index * 2);
		dfs(minmax_indices, root->right, depth + 1, index * 2 + 1);
	}
};