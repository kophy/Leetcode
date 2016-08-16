struct TrieNode {
    TrieNode *next[26];
    bool isString;

    TrieNode() {
        for(int i = 0; i < 26; ++i)
            next[i] = NULL;
        isString = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
for (auto word : words)
            insert(word);

        set<string> found;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                TrieNode* current = root;
                dfs(board, visited, i, j, "", current, found);
            }
        }
        vector<string> result;
for (auto word : found)
            result.push_back(word);
        return result;
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j,
             string word, TrieNode* current, set<string> &found) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j])
            return;
        char d = board[i][j];
        if (current->next[d - 'a'] == NULL)
            return;
        else if (current->next[d-'a']->isString) {
            word.push_back(d);
            current = current->next[d - 'a'];
            found.insert(word);
        } else {
            word.push_back(d);
            current = current->next[d-'a'];
        }
        visited[i][j] = true;
        dfs(board, visited, i + 1, j, word, current, found);
        dfs(board, visited, i, j + 1, word, current, found);
        dfs(board, visited, i - 1, j, word, current, found);
        dfs(board, visited, i, j - 1, word, current, found);
        visited[i][j] = false;
    }

private:
    TrieNode* root;

    void insert(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.size(); ++i) {
            if(p->next[word[i]-'a'] == NULL)
                p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->isString = true;
    }
};