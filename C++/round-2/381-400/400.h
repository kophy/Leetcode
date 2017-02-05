class Solution {
public:
    int findNthDigit(int n) {
        int k;
        long base = 1;

        // find the corresponding k-digits array
        for (k = 1; n > base * 9 * k; ++k) {
            n -= base * 9 * k;
            base *= 10;
        }

        // corresponding integer in the array
        string value = to_string(base + (n - 1) / k);

        // digit of the integer
        return value[(n - 1) % k] - '0';
    }
};