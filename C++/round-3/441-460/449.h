/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        serialize_help(result, root);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize_help(ss);
    }

private:
    void serialize_help(string &result, TreeNode *root) {
        if (root == NULL) {
            result += "# ";
            return;
        } else {
            result += to_string(root->val) + " ";
            serialize_help(result, root->left);
            serialize_help(result, root->right);
        }
    }

    TreeNode *deserialize_help(stringstream &ss) {
        string temp;
        ss >> temp;
        if (temp[0] == '#')
            return NULL;
        else {
            TreeNode *root = new TreeNode(stoi(temp));
            root->left = deserialize_help(ss);
            root->right = deserialize_help(ss);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));