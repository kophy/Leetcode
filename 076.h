class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(256, 0);
        int len = t.size();
        for (int i = 0; i < t.size(); ++i)
            ++count[t[i]];

        int start = -1, end = -1;
        int left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i]] > 0)
                --len;
            --count[s[i]];
            while (count[s[left]] < 0) {
                ++count[s[left]];
                ++left;
            }
            if (len == 0) {
                if (start == -1 || i - left < end - start) {
                    start = left;
                    end = i;
                }
            }
        }
        return (start < 0)? "" : s.substr(start, end - start + 1);
    }
};