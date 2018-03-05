class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		for (; root; root = root->left)
			data.push(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !data.empty();
	}

	/** @return the next smallest number */
	int next() {
		int result = data.top()->val;
		auto curr = data.top();
		data.pop();
		for (curr = curr->right; curr; curr = curr->left)
			data.push(curr);
		return result;
	}

private:
	stack<TreeNode *> data;
};