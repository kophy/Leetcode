class Solution {
public:
    int calculate(string s) {
        stack<int> data;
        char op = '+';
        int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c))
                num = 10 * num + (c - '0');
            if (!isdigit(c) && !isspace(c) || i == s.size() - 1) {
                if (op == '+' || op == '-')
                    data.push(op == '+'? num : -num);
                else {
                    int last = data.top();
                    data.pop();
                    data.push(op == '*'? last * num : last / num);
                }
                op = c;
                num = 0;
            }
        }
        // treat the whole expression as sum of terms
        int result = 0;
        while (!data.empty()) {
            result += data.top();
            data.pop();
        }
        return result;
    }
};