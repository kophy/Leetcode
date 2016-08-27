class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, n, 0, 0, "");
        return result;
    }

private:
    void generate(vector<string> &result, int n, int open, int close, string temp) {
        if (open == n && close == n) {
            result.push_back(temp);
            return;
        }
        if (open < n)
            generate(result, n, open + 1, close, temp + "(");
        if (close < open)
            generate(result, n, open, close + 1, temp + ")");
    }
};