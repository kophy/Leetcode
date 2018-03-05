class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int result = INT_MAX;
        int indices[] = {-1, -1};
        for (int i = 0; i < words.size(); ++i) {
            string &word = words[i];
            if (word == word1) {
                indices[0] = i;
                if (indices[1] >= 0)
                    result = min(result, i - indices[1]);
            }
            if (word == word2) {
                indices[1] = i;
                if (indices[0] >= 0)
                    result = min(result, i - indices[0]);
            }
        }
        return result;
    }
};