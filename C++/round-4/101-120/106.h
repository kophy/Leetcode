class Solution {
public:
	TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
		// Accelerate serach from value to index in inorder.
		unordered_map<int, int> m;
		for (int i = 0; i < inorder.size(); ++i)
			m[inorder[i]] = i;
		reverse(postorder.begin(), postorder.end());
		return buildTree(inorder, 0, (int)inorder.size(), postorder, 0, (int)postorder.size(), m);
	}

private:
	// Build tree with inorder[ib:ie] and reversed postorder[pb:pe].
	TreeNode* buildTree(vector<int> &inorder, int ib, int ie, vector<int> &postorder, int pb, int pe, unordered_map<int, int> &m) {
		if (ib >= ie || pb >= pe)
			return nullptr;
		int value = postorder[pb];
		TreeNode *root = new TreeNode(value);

		int idx = m[value];
		int dis = ie - idx - 1;         // number of elements in right subtree

		root->right = buildTree(inorder, idx + 1, ie, postorder, pb + 1, pb + 1 + dis, m);
		root->left = buildTree(inorder, ib, idx, postorder, pb + 1 + dis, pe, m);

		return root;
	}
};