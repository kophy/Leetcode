class TrieNode {
    public:
        unordered_map<char, TrieNode *> children;
        bool is_word;
        
        TrieNode() : is_word(false) {}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *curr = &root;
        for (char c : word) {
            if (!curr->children.count(c))
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(&root, word, 0);
    }
    
private:
    TrieNode root;
    
    bool search(TrieNode *node, string &word, int pos) {
        if (pos == word.size()) {
            return node->is_word;
        }
        if (word[pos] == '.') {
            for (auto &p : node->children) {
                TrieNode *child = p.second;
                if (search(child, word, pos + 1))
                    return true;
            }
            return false;
        } else {
            if (!node->children.count(word[pos]))
                return false;
            return search(node->children[word[pos]], word, pos + 1);
        }
    }
};