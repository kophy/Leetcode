class TrieNode {
    public:
        unordered_map<char, TrieNode *> children;
        bool is_word;
        int sum;
    
        TrieNode() {
            is_word = false;
            sum = 0;
        }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int old_val = search(key);
        TrieNode *curr = root;
        for (char c : key) {
            if (!curr->children.count(c))
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
            curr->sum += val - old_val;
        }
        curr->is_word = true;
    }
    
    int sum(string prefix) {
        TrieNode *curr = root;
        for (char c : prefix) {
            if (!curr->children.count(c))
                return 0;
            curr = curr->children[c];
        }
        return curr->sum;
    }
    
private:
    TrieNode *root;
    
    int search(string key) {
        TrieNode *curr = root;
        for (char c : key) {
            if (!curr->children.count(c))
                return 0;
            curr = curr->children[c];
        }
        return curr->is_word? curr->sum : 0;
    }
};