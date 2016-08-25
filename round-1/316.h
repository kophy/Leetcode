class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
		for (char c : s)
            ++count[c - 'a'];
        string result = "0";
		for (char c : s) {
            --count[c - 'a'];
            if (visited[c - 'a'])
                continue;
            while (c < result.back() && count[result.back() - 'a']) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result += c;
            visited[c - 'a'] = true;
        }
        return result.substr(1);
    }
};