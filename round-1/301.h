class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i]=='(')
                ++left;
            else if(s[i] == ')') {
                if(left > 0)
                    --left;
                else
                    ++right;
            }
        }
        unordered_set<string> result;
        help(result, "", s, 0, 0, left, right);
        return vector<string>(result.begin(), result.end());
    }

    void help(unordered_set<string> &result, string cur, string s, int pos, int pair, int left, int right) {
        if(pos == s.size()) {
            if(pair == 0 && left == 0 && right == 0)
                result.insert(cur);
            return;
        }
        if(s[pos] == '(') {
            /*** skip ***/
            if(left > 0) {
                help(result, cur, s, pos + 1, pair, left - 1, right);
            }
            /*** keep ***/
            help(result, cur + '(', s, pos + 1, pair + 1, left, right);
        } else if(s[pos] == ')') {
            /*** skip ***/
            if(right > 0)
                help(result, cur, s, pos + 1, pair, left, right - 1);
            /*** keep ***/
            /*** bug-places : I forget to check whether pair > 0 ***/
            if(pair > 0)
                help(result, cur + ')', s, pos + 1, pair - 1, left, right);
        } else
            help(result, cur + s[pos], s, pos + 1, pair, left, right);
    }
};