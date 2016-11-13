/* should remember this classic solution */
class Solution {
public:
    int calculate(string s) {
        stack<int> nums, sgns;
        int result = 0;
        int num = 0, sign = 1;

        for (char c : s) {
            /* case 1: digit */
            if (isdigit(c))
                num = num * 10 + (c - '0');
            /* case 2: non-digit -> before is a number */
            else {
                result += sign * num;
                num = 0;
                // case 2.1: sign
                if (c == '+' || c == '-')
                    sign = (c == '+')? 1 : -1;
                // case 2.2: '(' -> push
                else if (c == '(') {
                    nums.push(result);
                    sgns.push(sign);
                    result = 0, sign = 1;
                }
                // case 2.3: ')' -> pop
                else if (c == ')') {
                    result = sgns.top() * result + nums.top();
                    sgns.pop();
                    nums.pop();
                }
            }
        }
        result += sign * num;
        return result;
    }
};