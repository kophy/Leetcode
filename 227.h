class Solution {
public:
    int calculate(string s) {
        stack<int> data;
        char sign = '+';
        int temp = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i]))
                temp = 10 * temp + (s[i] - '0');
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {
                if (sign == '+' || sign == '-')
                    data.push(sign == '+'? temp : -temp);
                else {
                    int last = data.top();
                    data.pop();
                    data.push(sign == '*'? last * temp : last / temp);
                }
                sign = s[i];
                temp = 0;
            }
        }
        int result = 0;
        while (!data.empty()) {
            result += data.top();
            data.pop();
        }
        return result;
    }
};