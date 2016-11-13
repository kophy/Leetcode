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
        ostringstream sout;
        serialize_help(root, sout);
        return sout.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream sin(data);
        return deserialize_help(sin);
    }

private:
    void serialize_help(TreeNode *root, ostringstream &sout) {
        if (root) {
            sout << root->val << " ";
            serialize_help(root->left, sout);
            serialize_help(root->right, sout);
        } else
            sout << "# ";
    }

    TreeNode *deserialize_help(istringstream &sin) {
        string val;
        sin >> val;
        if (val == "#")
            return NULL;
        else {
            TreeNode *root = new TreeNode(stoi(val));
            root->left = deserialize_help(sin);
            root->right = deserialize_help(sin);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));