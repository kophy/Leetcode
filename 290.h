class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        vector<string> words;

        string temp;
        while (ss >> temp)
            words.push_back(temp);
        if (words.size() != pattern.size())
            return false;

        map<char, string> ch2str;
        set<string> used;
        for (int i = 0; i < pattern.size(); ++i) {
            if (ch2str.find(pattern[i]) == ch2str.end()) {
                if (used.find(words[i]) == used.end()) {
                    used.insert(words[i]);
                    ch2str[pattern[i]] = words[i];
                } else
                    return false;
            } else {
                if (ch2str[pattern[i]] != words[i])
                    return false;
            }
        }
        return true;
    }
};