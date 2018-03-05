class Solution {
public:
	int countUnivalSubtrees(TreeNode* root) {
		int count = 0;
		checkAndCount(count, root);
		return count;
	}

private:
	bool checkAndCount(int &count, TreeNode *root) {
		if (root == nullptr)
			return true;
		bool left = checkAndCount(count, root->left);
		bool right = checkAndCount(count, root->right);
		if (left && right) {
			if (root->left != nullptr && root->left->val != root->val)
				return false;
			if (root->right != nullptr && root->right->val != root->val)
				return false;
			++count;
			return true;
		} else
			return false;
	}
};