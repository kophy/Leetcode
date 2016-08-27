class Solution {
public:
    bool isValid(string s) {
        map<char, char> match;
        match['('] = ')';
        match['['] = ']';
        match['{'] = '}';

        stack<char> data;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (match.find(c) != match.end())
                data.push(c);
            else {
                if (data.empty() || match[data.top()] != c)
                    return false;
                data.pop();
            }
        }

        /* there maybe unused opening bracket */
        return data.empty();
    }
};