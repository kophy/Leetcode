class Solution {
public:
    int calculate(string s) {
        stack<int> last, ops;
        int curr = 0, op = 1;
        int result = 0;
        for (char c : s) {
            if (isdigit(c))
                curr = curr * 10 + (c - '0');
            else {
                result += op * curr;
                curr = 0;
                if (c == '+' || c == '-')
                    op = (c == '+')? 1 : -1;
                else if (c == '(') {
                    last.push(result);
                    ops.push(op);
                    result = 0;
                    op = 1;
                }
                else if (c == ')') {
                    result = last.top() + ops.top() * result;
                    last.pop();
                    ops.pop();
                }
            }
        }
        return (result + op * curr);
    }
};