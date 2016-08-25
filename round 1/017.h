class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters(10);
        letters[2] = "abc";
        letters[3] = "def";
        letters[4] = "ghi";
        letters[5] = "jkl";
        letters[6] = "mno";
        letters[7] = "pqrs";
        letters[8] = "tuv";
        letters[9] = "wxyz";

        vector<string> result;
        string curr;
        curr.resize(digits.size());
        combine_helper(result, letters, digits, curr, 0);
        return result;
    }
private:
    void combine_helper(vector<string> &result, vector<string> &letters,
                        string &digits, string &curr, int pos) {
        if (pos == digits.size()) {
            if (curr.size())
                result.push_back(curr);
            return;
        }
        int d = digits[pos] - '0';
        for (int i = 0; i < letters[d].size(); ++i) {
            curr[pos] = letters[d][i];
            combine_helper(result, letters, digits, curr, pos + 1);
        }
    }
};