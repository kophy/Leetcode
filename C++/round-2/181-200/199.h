/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
		vector<int> result;
		search(vector<int> &result, TreeNode *root, 0);
		return result;
    }
	
private:
	void search(vector<int> &result, TreeNode *root, int level) {
		if (result.size() == level)
			result.push_back(root->val);
		if (root->right)
			search(result, root->right, level + 1);
		if (root->left)
			search(result, root->left, level + 1);
	}
};