class Solution {
public:
	int findSecondMinimumValue(TreeNode* root) {
		set<int> data;
		traverse(data, root);
		if (data.size() < 2)
			return -1;
		else
			return *(++data.begin());
	}

private:
	void traverse(set<int> &data, TreeNode *root) {
		if (!root)
			return;
		data.insert(root->val);
		traverse(data, root->left);
		traverse(data, root->right);
	}
};