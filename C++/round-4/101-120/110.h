class Solution {
public:
	bool isBalanced(TreeNode* root) {
		int depth = 0;
		return checkAndCalculateDepth(root, depth);
	}

private:
	bool checkAndCalculateDepth(TreeNode *root, int &depth) {
		if (root == nullptr) {
			depth = 0;
			return true;
		}
		int left_depth = 0, right_depth = 0;
		bool left_balanced  = checkAndCalculateDepth(root->left, left_depth);
		bool right_balanced = checkAndCalculateDepth(root->right, right_depth);

		if (left_balanced && right_balanced && abs(left_depth - right_depth) <= 1) {
			depth = max(left_depth, right_depth) + 1;
			return true;
		} else
			return false;
	}
};