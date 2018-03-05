class TrieNode {
    public:
        unordered_map<char, TrieNode *> children;
        bool is_word;
    
        TrieNode() { is_word = false; }
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string &word : dict)
            insertWord(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return searchWord(root, word, 0);
    }
    
private:
    TrieNode *root;
    
    void insertWord(string &word) {
        TrieNode *curr = root;
        for (char c : word) {
            if (!curr->children.count(c))
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->is_word = true;
    }
    
    bool searchExactWord(TrieNode *root, string &word, int pos) {
        if (!root)
            return word.empty();
        TrieNode *curr = root;
        for (char c : word.substr(pos)) {
            if (!curr->children.count(c))
                return false;
            curr = curr->children[c];
        }
        return curr->is_word;
    }
    
    bool searchWord(TrieNode *root, string &word, int pos) {
        if (pos >= word.size())
            return false;
        char c = word[pos];
        for (auto &p : root->children) {
            if (p.first == c) {
                if (searchWord(p.second, word, pos + 1))
                    return true;
            } else {
                if (searchExactWord(p.second, word, pos + 1))
                    return true;
            }
        }
        return false;
    }
};