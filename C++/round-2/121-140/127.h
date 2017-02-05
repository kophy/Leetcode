class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> visited;
        queue<pair<string, int>> data;
        data.push(make_pair(beginWord, 1));

        /* BFS */
        while (!data.empty()) {
            string word = data.front().first;
            int length = data.front().second;
            data.pop();

            for (int i = 0; i < word.size(); ++i) {
                char d = word[i];
                // all possible words one step from current word
                for (int j = 0; j <= 25; ++j) {
                    word[i] = 'a' + j;
                    if (word == endWord)
                        return length + 1;
                    if (wordList.find(word) != wordList.end() && visited.find(word) == visited.end()) {
                        data.push(make_pair(word, length + 1));
                        visited.insert(word);
                    }
                }
                word[i] = d;
            }
        }
        return 0;
    }
};