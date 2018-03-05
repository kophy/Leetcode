class Solution {
public:
    string addStrings(string num1, string num2) {
        string result(max(num1.size(), num2.size()) + 1, '0');
        int i = num1.size() - 1, j = num2.size() - 1, k = result.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0)
                sum += num1[i--] - '0';
            if (j >= 0)
                sum += num2[j--] - '0';
            result[k--] = (sum % 10) + '0';
            carry = sum / 10;
        }
        return result[0] == '0'? result.substr(1) : result;
    }
};