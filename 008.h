class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        int i = 0;
        while (i < len && isspace(str[i]))
            ++i;

        int sign = 1;
        double result = 0;

        if (str[i] == '+' || str[i] == '-') {
            sign = (str[i] == '+')? 1 : -1;
            ++i;
        }
        while (i < len && isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
            ++i;
        }
        if (result > INT_MAX)
            result = (sign == 1)? INT_MAX : INT_MIN;
        else
            result = sign * result;
        return result;
    }
};