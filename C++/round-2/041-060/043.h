class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), '0');

        /*  don't think it as a M-digit number multiplies with a N-digit number
        	instead, think it as a M-digit number multiplies with a 1-digit number for N times,
        	and add for N times
        */
        for (int i = num1.size() - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                int temp = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;

                result[i + j + 1] = temp % 10 + '0';	// important: don't forget to plus '0' to convert int to char!

                carry = temp / 10;
            }
            result[i] += carry;
        }

        /* drop '0's at the beginning of result */
        int start = 0;
        while (start < result.size() && result[start] == '0')
            ++start;
        return (start < result.size())? result.substr(start) : "0";
    }
};