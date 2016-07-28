class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (int i = 0; i < digits.size(); ++i) {
            int d = digits[i] + carry;
            digits[i] = d % 10;
            carry = d / 10;
        }
        if (carry)
            digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};