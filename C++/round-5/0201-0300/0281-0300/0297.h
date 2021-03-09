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
  string serialize(TreeNode *root) {
    ostringstream oss;
    serialize_helper(root, oss);
    return oss.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    istringstream iss(data);
    return deserialize_helper(iss);
  }

 private:
  void serialize_helper(TreeNode *root, ostringstream &oss) {
    if (root == nullptr) {
      oss << "# ";
    } else {
      oss << root->val << " ";
      serialize_helper(root->left, oss);
      serialize_helper(root->right, oss);
    }
  }

  TreeNode *deserialize_helper(istringstream &iss) {
    TreeNode *root = nullptr;
    string val;
    iss >> val;
    if (val != "#") {
      root = new TreeNode(stoi(val, nullptr, 10));
      root->left = deserialize_helper(iss);
      root->right = deserialize_helper(iss);
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));