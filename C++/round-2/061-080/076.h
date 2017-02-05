class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> balance(256, 0);
        for (int i = 0; i < t.size(); ++i)
            --balance[t[i]];

        int unmatched = t.size();

        int min_begin = -1, min_len = -1;
        int begin = 0;

        for (int i = 0; i < s.size(); ++i) {
            /* calculate the number of characters not covered by current window string */
            if (balance[s[i]] < 0)
                --unmatched;
            ++balance[s[i]];

            /* drop needless characters from begin of current window string */
            while (balance[s[begin]] > 0) {
                --balance[s[begin]];
                ++begin;
            }

            /* update min_begin and min_len if required */
            if (unmatched == 0) {
                if (min_begin == -1 || i - begin + 1 < min_len) {
                    min_begin = begin;
                    min_len = i - begin + 1;
                }
            }
        }
        return min_begin < 0? "" : s.substr(min_begin, min_len);
    }
};