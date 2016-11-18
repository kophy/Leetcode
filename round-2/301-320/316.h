class Solution {
public:
    /* sliding window */
    string removeDuplicateLetters(string s) {
        vector<int> count(256, 0);              // count of a character in the rest string
        vector<bool> visited(256, false);       // whether current subsequence contains a character

        for (char c : s)
            ++count[c];
        string result = "";
        for (char c : s) {
            --count[c];
            if (visited[c])
                continue;
            // "shrink" the window
            while (!result.empty() && result.back() > c && count[result.back()]) {
                visited[result.back()] = false;
                result.pop_back();
            }
            result.push_back(c);
            visited[c] = true;
        }
        return result;
    }
};