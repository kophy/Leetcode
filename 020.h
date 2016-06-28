class Solution {
public:
    bool isValid(string s) {
        stack<char> unclosed;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                unclosed.push('(');
            else if (s[i] == '[')
                unclosed.push('[');
            else if (s[i] == '{')
                unclosed.push('{');
            else if (s[i] == ')') {
                if (unclosed.empty() || unclosed.top() != '(')
                    return false;
                unclosed.pop();
            } else if (s[i] == ']') {
                if (unclosed.empty() || unclosed.top() != '[')
                    return false;
                unclosed.pop();
            } else if (s[i] == '}') {
                if (unclosed.empty() || unclosed.top() != '{')
                    return false;
                unclosed.pop();
            }
        }
        return unclosed.empty();
    }
};