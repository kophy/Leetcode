class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> s2t;
        unordered_set<char> visited;
        for (int i = 0; i < s.size(); ++i) {
            char a = s[i], b = t[i];
            if (s2t.find(a) == s2t.end()) {
                if (visited.find(b) != visited.end())
                    return false;
                s2t[a] = b;
                visited.insert(b);
            } else {
                if (s2t[a] != b)
                    return false;
            }
        }
        return true;
    }
};