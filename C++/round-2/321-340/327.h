class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sum(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i)
            sum[i + 1] = sum[i] + nums[i];
        return conquer(sum, lower, upper, 0, nums.size() + 1);
    }
private:
    int conquer(vector<long>& sum, int lower, int upper, int left, int right) {
        if (right <= left + 1)
            return 0;
        int middle = (left + right) / 2;
        int count = conquer(sum, lower, upper, left, middle) + conquer(sum, lower, upper, middle, right);

        /*  both the left half and right half are respectively sorted,
            so we can remember m and n to avoid repeated search. */
        int m = middle, n = middle;
        for(int i = left; i < middle; ++i) {
            while(m < right && sum[m] - sum[i] < lower)
                ++m;
            n = m;
            while(n < right && sum[n] - sum[i] <= upper)
                ++n;
            count += n - m;
        }
        inplace_merge(sum.begin() + left, sum.begin() + middle, sum.begin() + right);
        return count;
    }
};