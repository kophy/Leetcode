typedef struct trienode {
    bool completed;
    trienode *children[26];
    trienode() {
        completed = false;
        memset(children, NULL, sizeof(trienode *) * 26);
    }
} trienode;

class WordDictionary {
public:
    WordDictionary() {
        root = new trienode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        trienode *curr = root;
        for (char c : word) {
            int d = c - 'a';
            if (curr->children[d] == NULL)
                curr->children[d] = new trienode();
            curr = curr->children[d];
        }
        curr->completed = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word, 0, root);
    }

private:
    bool query(string word, int pos, trienode *curr) {
        if (pos == word.size())
            return curr->completed;
        else if (word[pos] != '.') {
            int d = word[pos] - 'a';
            return curr->children[d] && query(word, pos + 1, curr->children[d]);
        } else {
            for (auto child : curr->children)
                if (child && query(word, pos + 1, child))
                    return true;
            return false;
        }
    }

    trienode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");