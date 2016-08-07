class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode() {
        isKey = false;
        memset(children, NULL, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* run = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!(run->children[word[i] - 'a']))
                run->children[word[i] - 'a'] = new TrieNode();
            run = run->children[word[i] - 'a'];
        }
        run->isKey = true;
    }

    bool search(string word) {
        return query(word.c_str(), root);
    }

private:
    TrieNode* root;

    bool query(const char* word, TrieNode* node) {
        TrieNode* run = node;
        for (int i = 0; word[i]; ++i) {
            if (run && word[i] != '.')
                run = run -> children[word[i] - 'a'];
            else if (run && word[i] == '.') {
                TrieNode* temp = run;
                for (int j = 0; j < 26; j++) {
                    run = temp -> children[j];
                    if (query(word + i + 1, run))
                        return true;
                }
            } else
                return false;;
        }
        return run && run->isKey;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");