class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size())
            combine_help(result, digits, 0, "");
        return result;
    }

private:
    string dict[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void combine_help(vector<string> &result, string &digits, int pos, string temp) {
        if (pos == digits.size()) {
            result.push_back(temp);
            return;
        }
        string choices = dict[digits[pos] - '0'];
        if (choices.size()) {
            for (int i = 0; i < choices.size(); ++i) {
                temp.push_back(choices[i]);
                combine_help(result, digits, pos + 1, temp);
                temp.pop_back();
            }
        } else
            combine_help(result, digits, pos + 1, temp);
    }
};