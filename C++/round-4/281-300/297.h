class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        serialize(data, root);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }
    
private:
    void serialize(string& data, TreeNode *root) {
        if (root == nullptr) {
            data += "# ";
            return;
        } else {
            data += to_string(root->val) + " ";
            serialize(data, root->left);
            serialize(data, root->right);
        }
    }
    
    TreeNode* deserialize(stringstream& ss) {
        string temp;
        ss >> temp;
        if (temp == "#")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(temp));
        root->left = deserialize(ss);
        root->right = deserialize(ss);
        return root;
    }
};