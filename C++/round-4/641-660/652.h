class Solution {
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		unordered_map<string, vector<TreeNode*>> data;
		encodeAndRecord(data, root);

		vector<TreeNode*> result;
		for (auto iter = data.begin(); iter != data.end(); ++iter)
			if (iter->second.size() > 1)
				result.push_back(iter->second[0]);
		return result;
	}
private:
	string encodeAndRecord(unordered_map<string, vector<TreeNode*>> &data, TreeNode *root) {
		if (!root)
			return "()";
		string key = "(" + to_string(root->val) + encodeAndRecord(data, root->left) + encodeAndRecord(data, root->right) + ")";
		data[key].push_back(root);
		return key;
	}
};