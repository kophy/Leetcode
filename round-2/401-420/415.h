class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        int k = max(num1.size(), num2.size());
        string result(k + 1, '0');
        while (i >= 0 || j >= 0 || carry) {
            int n1 = (i >= 0)? num1[i--] - '0' : 0;
            int n2 = (j >= 0)? num2[j--] - '0' : 0;
            int temp = n1 + n2 + carry;
            result[k--] = temp % 10 + '0';
            carry = temp / 10;
        }

        return k? result : result.substr(1);
    }
};