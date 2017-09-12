class Solution {
public:
	TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
		return constructMaximumBinaryTree(nums, 0, (int)nums.size() - 1);
	}

private:
	TreeNode *constructMaximumBinaryTree(vector<int> &nums, int l, int r) {
		if (l > r)
			return nullptr;
		int idx = l;
		for (int i = l; i <= r; ++i)
			idx = (nums[i] > nums[idx])? i : idx;
		TreeNode *root = new TreeNode(nums[idx]);
		root->left = constructMaximumBinaryTree(nums, l, idx - 1);
		root->right = constructMaximumBinaryTree(nums, idx + 1, r);
		return root;
	}
};