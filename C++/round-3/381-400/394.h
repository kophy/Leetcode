class Solution {
public:
    string decodeString(string s) {
        stack<int> cnt_stk;
        stack<string> str_stk;
        string result = "";
        int count = 0;

for (char c : s) {
            if (isdigit(c))
                count = count * 10 + (c - '0');
            else if (isalpha(c)) {
                // case 1: not in bracket
                if (str_stk.empty())
                    result.push_back(c);
                // case 2: in bracket
                else
                    str_stk.top().push_back(c);
            } else if (c == '[') {
                cnt_stk.push(count);
                count = 0;
                str_stk.push("");
            } else if (c == ']') {
                string temp = "";
                for (int i = 0; i < cnt_stk.top(); ++i)
                    temp += str_stk.top();
                cnt_stk.pop();
                str_stk.pop();
                if (str_stk.empty())
                    result += temp;
                else
                    str_stk.top() += temp;
            }
        }
        return result;
    }
};