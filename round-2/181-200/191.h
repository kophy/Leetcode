class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        /* removes one bit each loop */
        while (n > 0) {
            n &= (n - 1);
            ++count;
        }
        return count;
    }
};