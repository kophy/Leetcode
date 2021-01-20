class Solution {
 public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                               vector<int> &rightChild) {
    vector<TreeNode *> nodes;
    unordered_set<int> root;
    for (int i = 0; i < n; ++i) {
      nodes.push_back(new TreeNode(i));
      root.insert(i);
    }

    for (int i = 0; i < n; ++i) {
      if (leftChild[i] != -1) {
        nodes[i]->left = nodes[leftChild[i]];
        root.erase(leftChild[i]);
      }
      if (rightChild[i] != -1) {
        nodes[i]->right = nodes[rightChild[i]];
        root.erase(rightChild[i]);
      }
    }

    if (root.size() != 1) {
      return false;
    }

    unordered_set<int> elements;
    if (!checkBinaryTree(nodes[*root.begin()], elements)) {
      return false;
    }
    return elements.size() == n;
  }

 private:
  bool checkBinaryTree(TreeNode *root, unordered_set<int> &elements) {
    if (root == nullptr) {
      return true;
    }
    if (elements.count(root->val)) {
      return false;
    }
    elements.insert(root->val);
    return checkBinaryTree(root->left, elements) &&
           checkBinaryTree(root->right, elements);
  }
};