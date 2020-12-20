struct TrieNode {
  bool is_word;
  map<char, TrieNode *> children;

  TrieNode() : is_word(false) {}
};

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    TrieNode *root = new TrieNode();
    for (const string &product : products) {
      insertWord(root, product);
    }
    vector<vector<string>> result(searchWord.size());
    TrieNode *curr = root;
    for (int i = 0; i < searchWord.size(); ++i) {
      if (curr == nullptr || !curr->children.count(searchWord[i])) {
        curr = nullptr;
        ;
      } else {
        curr = curr->children[searchWord[i]];
        string prefix = searchWord.substr(0, i + 1);
        for (const string &rest : listWords(curr)) {
          result[i].push_back(prefix + rest);
        }
      }
    }
    return result;
  }

private:
  void insertWord(TrieNode *root, const string &word) {
    for (char c : word) {
      if (!root->children.count(c)) {
        root->children[c] = new TrieNode();
      }
      root = root->children[c];
    }
    root->is_word = true;
  }

  vector<string> listWords(TrieNode *root) {
    vector<string> result;
    string path = "";
    int count = 3;
    helper(root, count, path, result);
    return result;
  }

private:
  void helper(TrieNode *root, int &count, string &path,
              vector<string> &result) {
    if (root == nullptr || count <= 0) {
      return;
    }
    if (root->is_word) {
      result.push_back(path);
      --count;
    }

    for (const auto &p : root->children) {
      path.push_back(p.first);
      helper(p.second, count, path, result);
      path.pop_back();
    }
  }
};