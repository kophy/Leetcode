class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.size(), j = b.size();
        int carry = 0;
        while(i || j || carry) {
            int n1 = i? a[--i] - '0' : 0;
            int n2 = j? b[--j] - '0' : 0;
            result = char((n1 + n2 + carry) % 2 + '0') + result;
            carry = (n1 + n2 + carry) / 2;
        }
        return result;
    }
};