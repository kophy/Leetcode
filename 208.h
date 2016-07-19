class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : is_word(false) {};
	map<char, TrieNode*> children;
	bool is_word;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* curr = root;
		for (int i = 0; i < word.size(); ++i) {
			if (curr->children.find(word[i]) == curr->children.end())
				curr->children[word[i]] = new TrieNode();
			curr = curr->children[word[i]];
		}
		curr->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* curr = root;
		for (int i = 0; i < word.size(); ++i) {
			if (curr->children.find(word[i]) == curr->children.end())
				return false;
			curr = curr->children[word[i]];
		}
		return curr->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* curr = root;
		for (int i = 0; i < prefix.size(); ++i) {
			if (curr->children.find(prefix[i]) == curr->children.end())
				return false;
			curr = curr->children[prefix[i]];
		}
		return true;
    }

private:
    TrieNode* root;
};