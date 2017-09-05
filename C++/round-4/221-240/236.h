class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// Use dfs to build a child-to-parent map.
		unordered_map<TreeNode *, TreeNode *> parent;
		stack<TreeNode *> data;
		if (root != nullptr)
			data.push(root);
		while (!data.empty()) {
			TreeNode *node = data.top();
			data.pop();
			if (node->left != nullptr) {
				parent[node->left] = node;
				data.push(node->left);
			}
			if (node->right != nullptr) {
				parent[node->right] = node;
				data.push(node->right);
			}
		}
		vector<TreeNode *> path_p = findPath(parent, p);
		vector<TreeNode *> path_q = findPath(parent, q);
		TreeNode *result = nullptr;
		for (int i = 0; i < min(path_p.size(), path_q.size()); ++i) {
			if (path_p[i] != path_q[i])
				break;
			result = path_p[i];
		}
		return result;
	}

private:
	vector<TreeNode *> findPath(unordered_map<TreeNode *, TreeNode *> &parent, TreeNode *node) {
		vector<TreeNode *> path;
		path.push_back(node);
		while (parent.count(node)) {
			node = parent[node];
			path.push_back(node);
		}
		reverse(path.begin(), path.end());
		return path;
	}
};