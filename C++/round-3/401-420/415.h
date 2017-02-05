class Solution {
public:
    string addStrings(string num1, string num2) {
        string result(max(num1.size(), num2.size()) + 1, ' ');
        int i = num1.size() - 1, j = num2.size() - 1, k = result.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int n1 = (i >= 0)? num1[i--] - '0': 0;
            int n2 = (j >= 0)? num2[j--] - '0': 0;
            int sum = n1 + n2 + carry;
            result[k--] = sum % 10 + '0';
            carry = sum / 10;
        }
        return result.substr(k + 1);
    }
};