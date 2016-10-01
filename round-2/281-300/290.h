class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = unravel(str);
        if (pattern.size() != words.size())
            return false;

        map<char, string> char2str;
        set<string> used;
        for (int i = 0; i < pattern.size(); ++i) {
            if (char2str.find(pattern[i]) == char2str.end()) {
                if (used.find(words[i]) == used.end()) {
                    char2str[pattern[i]] = words[i];
                    used.insert(words[i]);
                } else
                    return false;
            } else if (char2str[pattern[i]] != words[i])
                return false;
        }
        return true;
    }

private:
    vector<string> unravel(string &str) {
        vector<string> words;
        stringstream ss(str);
        string temp;
        while (ss >> temp)
            words.push_back(temp);
        return words;
    }
};