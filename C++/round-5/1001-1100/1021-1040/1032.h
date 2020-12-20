class StreamChecker {
public:
  StreamChecker(vector<string> &words) {
    root = new SuffixTreeNode();
    max_length = 0;
    for (string &word : words) {
      insertWord(root, word);
      max_length = max(max_length, (int)word.size());
    }
  }

  bool query(char letter) {
    buffer.push_back(letter);
    if (buffer.size() > max_length) {
      buffer = buffer.substr(1);
    }
    return findWord(root, buffer);
  }

private:
  typedef struct SuffixTreeNode {
    bool is_leaf;
    unordered_map<char, SuffixTreeNode *> children;
    SuffixTreeNode() : is_leaf(false) {}
  };

  void insertWord(SuffixTreeNode *root, string &word) {
    string reversed_word = word;
    reverse(reversed_word.begin(), reversed_word.end());
    insertWordHelper(root, reversed_word, 0);
  }

  void insertWordHelper(SuffixTreeNode *root, string &reversed_word,
                        int index) {
    if (index == reversed_word.size()) {
      root->is_leaf = true;
      return;
    }
    char c = reversed_word[index];
    if (!root->children.count(c)) {
      root->children[c] = new SuffixTreeNode();
    }
    insertWordHelper(root->children[c], reversed_word, index + 1);
  }

  bool findWord(SuffixTreeNode *root, string &word) {
    string reversed_word = word;
    reverse(reversed_word.begin(), reversed_word.end());
    return findWordHelper(root, reversed_word, 0);
  }

  bool findWordHelper(SuffixTreeNode *root, string &reversed_word, int index) {
    if (root->is_leaf) {
      return true;
    }
    if (index == reversed_word.size()) {
      return root->is_leaf;
    }
    char c = reversed_word[index];
    if (root->children.count(c)) {
      return findWordHelper(root->children[c], reversed_word, index + 1);
    }
    return false;
  }

  SuffixTreeNode *root;
  int max_length;
  string buffer;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
