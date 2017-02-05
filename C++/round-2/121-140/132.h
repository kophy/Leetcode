class Solution {
public:
    int minCut(string s) {
        int N = s.size();
        int cut[N + 1] = {0};

        /* worst case: no palindrome substring at all */
        for (int i = 0; i <= N; i++)
            cut[i] = i - 1;
        for (int i = 0; i < N; i++) {
            /* odd length palindrome substring */
            for (int j = 0; i - j >= 0 && i + j < N && s[i - j] == s[i + j]; ++j)
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);
            /* even length palindrome substring */
            for (int j = 1; i - j + 1 >= 0 && i + j < N && s[i - j + 1] == s[i + j]; ++j)
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j + 1]);
        }
        return cut[s.size()];
    }
};