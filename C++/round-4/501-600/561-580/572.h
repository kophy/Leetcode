class Solution {
public:
	bool isSubtree(TreeNode *s, TreeNode *t) {
		if (!s)
			return false;
		if (isSameTree(s, t))
			return true;
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}

private:
	bool isSameTree(TreeNode *s, TreeNode *t) {
		if (!s && !t)
			return true;
		else if (!s || !t)
			return false;
		else
			return (s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
	}
};