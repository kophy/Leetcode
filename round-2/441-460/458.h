class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        --buckets;
        int base = minutesToTest / minutesToDie + 1;
        int count = 0;
        while (buckets) {
            buckets /= base;
            ++count;
        }
        return count;
    }
};