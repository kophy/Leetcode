class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        ostringstream oss;
        for (string &str : strs)
            oss << str.size() << " " << str;
        return oss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int pos = 0;
        while (pos < s.size()) {
            int k = 0;
            while (s[pos + k] != ' ')
                ++k;
            int len = stoi(s.substr(pos, k));
            pos += k + 1;
            strs.push_back(s.substr(pos, len));
            pos += len;
        }
        return strs;
    }
};