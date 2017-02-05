class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            return addBinary(b, a);
        int carry = 0;
        int pa = a.size() - 1, pb = b.size() - 1;

        while (pa >= 0 || pb >= 0) {
            int n1 = (pa >= 0)? a[pa] - '0' : 0;
            int n2 = (pb >= 0)? b[pb] - '0' : 0;
            int sum = n1 + n2 + carry;

            /* pay attention to array type! */
            a[pa] = sum % 2 + '0';

            carry = sum / 2;
            --pa, --pb;
        }
        if (carry)
            a.insert(a.begin(), '1');
        return a;
    }
};