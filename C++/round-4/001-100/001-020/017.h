class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() > 0) {
            string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            string candidate;
            backtracking(result, dict, digits, 0, candidate);
        }
        return result;
    }
    
private:
    void backtracking(vector<string>& result, string* dict, string& digits, int pos, string& candidate) {
        if (pos == digits.size()) {
            result.push_back(candidate);
            return;
        }
        int digit = digits[pos] - '0';
        for (char c : dict[digit]) {
            candidate.push_back(c);
            backtracking(result, dict, digits, pos + 1, candidate);
            candidate.pop_back();
        }
    }
};