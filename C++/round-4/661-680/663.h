class Solution {
public:
	bool checkEqualTree(TreeNode* root) {
		unordered_map<int, int> data;
		int sum = sumAndRecord(data, root);
		if (sum % 2 != 0)
			return false;
		else if (sum == 0)
			return data[0] > 1;
		else
			return data[sum / 2] > 0;
	}

private:
	int sumAndRecord(unordered_map<int, int> &data, TreeNode *root) {
		if (!root)
			return 0;
		int sum = root->val + sumAndRecord(data, root->left) + sumAndRecord(data, root->right);
		++data[sum];
		return sum;
	}
};