class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pattern(26, 0), count(26, 0);
        int K = p.size();
        for (int i = 0; i < K; ++i)
            ++pattern[p[i] - 'a'];

        vector<int> result;
        for (int i = 0; i < s.size(); ++i) {
            ++count[s[i] - 'a'];
            if (i >= K)
                --count[s[i - K] - 'a'];
            if (i >= K - 1 && anagram(count, pattern))
                result.push_back(i - K + 1);
        }
        return result;
    }

private:
    bool anagram(vector<int> &count, vector<int> &pattern) {
        for (int i = 0; i < 26; ++i)
            if (count[i] != pattern[i])
                return false;
        return true;
    }
};