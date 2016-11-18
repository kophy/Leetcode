class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        generate(result, word, "", 0, true);
        return result;
    }

private:
    void generate(vector<string> &result, string &word, string temp, int pos, bool allow_abbr) {
        if (pos == word.size()) {
            result.push_back(temp);
            return;
        }
        // add an abbr if allows
        if (allow_abbr) {
            for (int len = 1; pos + len <= word.size(); ++len)
                generate(result, word, temp + to_string(len), pos + len, false);
        }
        // always can add one character
        generate(result, word, temp + word[pos], pos + 1, true);
    }
};