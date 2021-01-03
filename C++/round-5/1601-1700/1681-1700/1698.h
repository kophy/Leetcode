struct TrieNode {
  vector<TrieNode *> children;

  TrieNode() { children = vector<TrieNode *>(26, nullptr); }
};

class Solution {
 public:
  int countDistinct(string s) {
    int result = 0;
    TrieNode root;
    for (int i = 0; i < s.size(); ++i) {
      result += insert(&root, s, i);
    }
    return result;
  }

 private:
  // The number of initialized nodes are the number of unique substrings.
  int insert(TrieNode *root, const string &s, int begin) {
    int new_count = 0;
    for (int i = begin; i < s.size(); ++i) {
      char c = s[i];
      int index = c - 'a';
      if (root->children[index] == nullptr) {
        root->children[index] = new TrieNode();
        ++new_count;
      }
      root = root->children[index];
    }
    return new_count;
  }
};