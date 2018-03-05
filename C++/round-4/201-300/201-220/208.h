struct TrieNode {
	unordered_map<char, TrieNode *> children;
	bool completed_;

	TrieNode() : completed_(false) {}
};

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *curr = root;
for (char c : word) {
			if (!curr->children.count(c))
				curr->children[c] = new TrieNode();
			curr = curr->children[c];
		}
		curr->completed_ = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode *curr = root;
for (char c : word) {
			if (!curr->children.count(c))
				return false;
			curr = curr->children[c];
		}
		return curr->completed_;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode *curr = root;
for (char c : prefix) {
			if (!curr->children.count(c))
				return false;
			curr = curr->children[c];
		}
		return true;
	}

private:
	TrieNode *root;
};