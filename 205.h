class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        map<char, char> my_map;
        vector<bool> used(256, false);

        for (int i = 0; i < s.size(); ++i) {
            if (my_map.find(s[i]) == my_map.end()) {
                if (used[t[i]])
                    return false;
                else {
                    my_map[s[i]] = t[i];
                    used[t[i]] = true;
                }
            } else {
                if (my_map[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};