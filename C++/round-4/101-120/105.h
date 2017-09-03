class Solution {
public:
	TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
		// Accelerate serach from value to index in inorder.
		unordered_map<int, int> m;
		for (int i = 0; i < inorder.size(); ++i)
			m[inorder[i]] = i;
		return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size(), m);
	}

private:
	// Build tree with preorder[pb:pe] and inorder[ib:ie].
	TreeNode* buildTree(vector<int> &preorder, int pb, int pe, vector<int> &inorder, int ib, int ie, unordered_map<int, int> &m) {
		if (pb >= pe || ib >= ie)
			return nullptr;

		int value = preorder[pb];
		TreeNode* root = new TreeNode(value);

		int idx = m[value];
		int dis = idx - ib;      

		root->left = buildTree(preorder, pb + 1, pb + 1 + dis, inorder, ib, idx, m);
		root->right = buildTree(preorder, pb + 1 + dis, pe, inorder, idx + 1, ie, m);
		return root;
	}
};