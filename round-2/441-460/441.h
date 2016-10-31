class Solution {
public:
    int arrangeCoins(int n) {
        return (-1 + sqrt(1 + n * 8.0)) / 2;
    }
};