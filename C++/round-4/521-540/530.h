class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		int result = INT_MAX;

		stack<TreeNode *> data;
		for (; root; root = root->left)
			data.push(root);
		TreeNode *last = nullptr;
		while (!data.empty()) {
			TreeNode *curr = data.top();
			data.pop();
			if (last)
				result = min(result, curr->val - last->val);
			last = curr;
			curr = curr->right;
			for (; curr; curr = curr->left)
				data.push(curr);
		}
		return result;
	}
};