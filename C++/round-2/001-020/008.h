class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while (isspace(str[i]))
            ++i;
        int op = 1;
        if (str[i] == '+' || str[i] == '-') {
            op = (str[i] == '+')? 1 : -1;
            ++i;
        }
        long result = 0, temp = 0;
        for ( ; i < str.size() && isdigit(str[i]); ++i) {
            temp = temp * 10 + (str[i] - '0');

            /* compare actual value with the bound of INT_MIN and INT_MAX */
            result = op * temp;
            if (result < INT_MIN)
                return INT_MIN;
            if (result > INT_MAX)
                return INT_MAX;
        }
        return result;
    }
};