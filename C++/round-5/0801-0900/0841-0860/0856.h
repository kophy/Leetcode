class Solution {
public:
    int scoreOfParentheses(string S) {
        int depth = 0, result = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                ++depth;
            } else {
                if (S[i - 1] == '(') {
                    result += 1 << (depth - 1);
                }
                --depth;
            }
        }
        return result;
    }
};