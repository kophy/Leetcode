class Solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        multiset<long> appeared_sum;
        appeared_sum.insert(0);

        int result = 0;
        long sum = 0;
        for (int num : nums) {
            sum += num;
            auto start = appeared_sum.lower_bound(sum - upper);
            auto end = appeared_sum.upper_bound(sum - lower);
            result += distance(start, end);
            appeared_sum.insert(sum);
        }
        return result;
    }
};