// preorder traversal
class Solution {
public:
	void flatten(TreeNode *root) {
		TreeNode dummy(0), *curr = &dummy;
		stack<TreeNode *> data;
		if (root != nullptr)
			data.push(root);
		while (!data.empty()) {
			TreeNode *node = data.top();
			data.pop();
			if (node->right != nullptr) {
				data.push(node->right);
				node->right = nullptr;
			}
			if (node->left != nullptr) {
				data.push(node->left);
				node->left = nullptr;
			}
			curr->right = node;
			curr = curr->right;
		}
	}
};