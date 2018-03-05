class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "# ";
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }
    
private:
    TreeNode *deserialize(stringstream &ss) {
        string val;
        ss >> val;
        if (val == "#")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(ss);
        root->right = deserialize(ss);
        return root;
    }
};