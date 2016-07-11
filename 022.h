class Solution {
public:
    vector<string> generateParenthesis(int n) {
        result.clear();
        generate_helper(n, "", 0, 0);
        return result;
    }

private:
    vector<string> result;

    void generate_helper(int n, string curr, int left_count, int right_count) {
        if (left_count == n && right_count == n)
            result.push_back(curr);
        else {
            if (left_count < n)
                generate_helper(n, curr + '(', left_count + 1, right_count);
            if (right_count < left_count)
                generate_helper(n, curr + ')', left_count, right_count + 1);
        }
    }
};