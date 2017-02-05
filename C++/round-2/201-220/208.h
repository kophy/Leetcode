class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : completed(false) {}
    map<char, TrieNode *> data;
    bool completed;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (curr->data.find(c) == curr->data.end())
                curr->data[c] = new TrieNode();
            curr = curr->data[c];
        }
        curr->completed = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (curr->data.find(c) == curr->data.end())
                return false;
            curr = curr->data[c];
        }
        return curr->completed;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); ++i) {
            char c = prefix[i];
            if (curr->data.find(c) == curr->data.end())
                return false;
            curr = curr->data[c];
        }
        return true;
    }

private:
    TrieNode *root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");