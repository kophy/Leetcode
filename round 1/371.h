class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0)
            return b;
        else if (b == 0)
            return a;
        else
            return getSum(a ^ b, (a & b) << 1);
    }
};