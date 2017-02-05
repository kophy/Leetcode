class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pattern(26, 0), count(26, 0);
        int len = p.size();
        for (int i = 0; i < len; ++i)
            ++pattern[p[i] - 'a'];

        vector<int> result;
        for (int i = 0; i < s.size(); ++i) {
            /* sliding window */
            ++count[s[i] - 'a'];
            if (i >= len)
                --count[s[i - len] - 'a'];
            if (i >= len - 1 && isAnagram(count, pattern))
                result.push_back(i - len + 1);
        }
        return result;
    }

private:
    bool isAnagram(vector<int> &count, vector<int> &pattern) {
        for (int i = 0; i < 26; ++i)
            if (count[i] != pattern[i])
                return false;
        return true;
    }
};